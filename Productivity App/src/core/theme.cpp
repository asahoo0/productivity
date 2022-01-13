//
// Created by asaho on 4/27/2021.
//

#include "core/theme.h"

namespace productivity {
    Theme::Theme(std::string background, std::string font, std::string name) {
        background_color_ = background;
        font_color_ = font;
        name_ = name;
    }

    std::string &Theme::GetName() {
        return name_;
    }

    std::string &Theme::GetFontColor() {
        return font_color_;
    }

    std::string &Theme::GetBackgroundColor() {
        return background_color_;
    }

    Theme::Theme() {
        //default theme dark mode
        background_color_ = "black";
        font_color_ = "white";
        name_ = "dark";
    }
}
