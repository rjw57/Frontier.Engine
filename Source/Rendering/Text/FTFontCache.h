﻿#pragma once
#include <Frontier.h>
#include <Rendering/Text/FTFont.h>


class FTFontCache {
    friend class FTEngine;
public:

    bool loadFont(const std::basic_string<char>& name);

    std::shared_ptr<FTFont>& getFont(const std::basic_string<char>& string) {
        auto it = loaded_fonts_.find(string);
        if (it == loaded_fonts_.end()) {
            loadFont(string);
            it = loaded_fonts_.find(string);
        }
        FTAssert(it != loaded_fonts_.end(), "Could not find Font %s", string);
        return it->second;
    }

protected:
    std::unordered_map<std::basic_string<char>, std::shared_ptr<FTFont>> loaded_fonts_;

    FTFontCache();
    ~FTFontCache();
};
