﻿#pragma once
#include <Rendering/Scene/FTNode.h>
#include <Rendering/Mesh/FTIndexedTexturedMesh.h>
#include "FTFont.h"
#include <Rendering/Shader/FTFontShader.h>

class FTLabel : public FTIndexedTexturedMesh<FTFontShader, FTVertexColorTexture<glm::vec2>, uint16_t> {
public:
    FTLabel(const std::string& fontpath, const std::basic_string<wchar_t>& text, int font_size, bool is_mutable = false);
    virtual ~FTLabel();

    void setString(const wchar_t* text);

protected:
    std::shared_ptr<FTIndexedMeshData<FTVertexColorTexture<glm::vec2>, uint16_t>> mesh_data_;
    std::shared_ptr<FTFont> font_;
    std::basic_string<wchar_t> text_;

    bool is_mutable_;
    int font_size_;
};
