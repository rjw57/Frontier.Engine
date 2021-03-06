#include "FTCamera3D.h"
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Rendering/Scene/FTNode.h>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_vec2.hpp>
#include <glm/detail/type_vec4.hpp>


FTCamera3D::FTCamera3D() : position_(0, 0, 0), rotation_euler_radians(0, 0), rotation_dirty_(true), update_view_frustrum_(true), fov_((float)M_PI_2) {

};

FTCamera3D::~FTCamera3D() {

}

void FTCamera3D::preDraw() {
    FTCamera::preDraw();
    if (projection_matrix_dirty_) {
        projection_matrix_ = glm::perspective(fov_, (float)draw_rect_abs_.width_ / (float)draw_rect_abs_.height_, near_clipping_plane_, far_clipping_plane_);
    }
    if (view_matrix_dirty_) {
        if (rotation_dirty_) {
            look_direction_ = glm::vec3(cos(rotation_euler_radians.y) * sin(rotation_euler_radians.x), sin(rotation_euler_radians.y), cos(rotation_euler_radians.y) * -cos(rotation_euler_radians.x));

            right_vector_ = glm::vec3(cos(rotation_euler_radians.x), 0, sin(rotation_euler_radians.x));
            up_vector_ = glm::cross(right_vector_, look_direction_);

            rotation_dirty_ = false;
        }
        view_matrix_ = glm::lookAt(position_, look_direction_ + position_, up_vector_);
    }
    if (view_matrix_dirty_ || projection_matrix_dirty_) {
        view_projection_matrix_ = projection_matrix_.getData() * view_matrix_.getData();
        if (update_view_frustrum_)
            regenerateViewFrustrum();
        view_matrix_dirty_ = false;
        projection_matrix_dirty_ = false;
        view_projection_matrix_inv_dirty_ = true;
    }
}

bool FTCamera3D::testNodeVisible(const FTNode* node) const {
    glm::vec3 half_extents = node->getAABHalfExtents();
    glm::vec3 center = node->getAABCenter();

    return testBoundingBox(center, half_extents);
}

FTRaycast FTCamera3D::generateRaycastForMousePos(double x, double y) {
    if (view_projection_matrix_inv_dirty_) {
        view_projection_matrix_inv_ = glm::inverse(view_projection_matrix_.getConstData());
    }

    glm::vec3 near_vector = unProject(glm::vec3(x, y, 0));
    glm::vec3 far_vector = unProject(glm::vec3(x, y, 1));

    glm::vec3 direction = glm::vec3(far_vector.x - near_vector.x, far_vector.y - near_vector.y, far_vector.z - near_vector.z);
    direction = glm::normalize(direction);
    return FTRaycast(position_, direction);
}

bool FTCamera3D::testBoundingBox(glm::vec3& center, glm::vec3& halfextents) const {
    for (int i = 0; i < 6; i++) {
        glm::vec3 res = center + vec3xor(halfextents, frustrum_planes_sign_flipped_[i]);
        if (glm::dot(res, *(glm::vec3*)&(frustrum_planes_[i].getConstData())) <= -frustrum_planes_[i].getConstData().w)
            return false;
    }
    return true;
}

glm::vec4 normalizeVec4(const glm::vec4& vec) {
    float d = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    return vec / d;
}

float InvSqrt(float x) {
    float xhalf;
    int i;

    xhalf = 0.5f * x;
    i = *(int*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
}

static inline float floatAnd(float f) {

    int i = ((*(int*)&f) & 0x80000000);
    return (*(float*)&i);
}

void FTCamera3D::regenerateViewFrustrum() {
    glm::mat4 matrix = projection_matrix_.getData() * view_matrix_.getData();
    glm::vec4 row1 = glm::row(matrix, 0);
    glm::vec4 row2 = glm::row(matrix, 1);
    glm::vec4 row3 = glm::row(matrix, 2);
    glm::vec4 row4 = glm::row(matrix, 3);

    // Near Plane
    glm::vec4& data0 = frustrum_planes_[0].getData();
    data0 = normalizeVec4(row4 + row3);
    frustrum_planes_sign_flipped_[0] = glm::vec3(floatAnd(data0.x), floatAnd(data0.y), floatAnd(data0.z));
    // Far Plane
    glm::vec4& data1 = frustrum_planes_[1].getData();
    data1 = normalizeVec4(row4 - row3);
    frustrum_planes_sign_flipped_[1] = glm::vec3(floatAnd(data1.x), floatAnd(data1.y), floatAnd(data1.z));

    // Left Plane
    glm::vec4& data2 = frustrum_planes_[2].getData();
    data2 = normalizeVec4(row4 + row1);
    frustrum_planes_sign_flipped_[2] = glm::vec3(floatAnd(data2.x), floatAnd(data2.y), floatAnd(data2.z));

    // Right Plane
    glm::vec4& data3 = frustrum_planes_[3].getData();
    data3 = normalizeVec4(row4 - row1);
    frustrum_planes_sign_flipped_[3] = glm::vec3(floatAnd(data3.x), floatAnd(data3.y), floatAnd(data3.z));

    // Top Plane
    glm::vec4& data4 = frustrum_planes_[4].getData();
    data4 = normalizeVec4(row4 + row2);
    frustrum_planes_sign_flipped_[4] = glm::vec3(floatAnd(data4.x), floatAnd(data4.y), floatAnd(data4.z));

    // Bottom Plane
    glm::vec4& data5 = frustrum_planes_[5].getData();
    data5 = normalizeVec4(row4 - row2);
    frustrum_planes_sign_flipped_[5] = glm::vec3(floatAnd(data5.x), floatAnd(data5.y), floatAnd(data5.z));
}
