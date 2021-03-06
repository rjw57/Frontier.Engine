﻿#include "FTLabel.h"
#include <Rendering/Shader/FTShaderCache.h>
#include <FTEngine.h>
#include "FTFontCache.h"

FTLabel::FTLabel(const std::string& fontpath, const std::basic_string<wchar_t>& text, int font_size, bool is_mutable) : FTIndexedTexturedMesh(), is_mutable_(is_mutable), font_size_(font_size) {

    font_ = FTEngine::getDirector()->getFontCache()->getFont(fontpath);

    glm::vec2 pen;
    auto data = construct_unique(font_->generateMeshForString(text, font_size, pen));
    setSize(glm::vec3(pen.x, pen.y, 0));

    auto texture = font_->getTexture();

    setTexture(texture);
    loadIndexedMeshData(data.get(), !is_mutable);

    if (is_mutable)
        mesh_data_ = std::move(data);

    text_ = text;
}


FTLabel::~FTLabel() {

}

void FTLabel::setString(const wchar_t* text) {
    if (text_ == text)
        return;

    text_ = text;

    FTAssert(is_mutable_, "Trying to change immutable FTLabel!");

    mesh_data_->getIndices().clear();
    mesh_data_->getVertices().clear();

    glm::vec2 pen;
    font_->populateMeshDataForString(mesh_data_.get(), text, font_size_, pen);
    setIndexedMeshData(mesh_data_.get());

    setSize(glm::vec3(pen.x, pen.y, 0));
}
