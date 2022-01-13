//
// Created by asaho on 4/27/2021.
//

#ifndef FINAL_PROJECT_THEME_H
#define FINAL_PROJECT_THEME_H
#pragma once

#include <string>

namespace productivity {

    /**
     * A theme is an object with a name, background color, and resources color
     */
    class Theme {
    public:
        /**
         *
         * @param background the background color
         * @param font the font color
         * @param name the theme name
         */
        Theme(std::string background, std::string font, std::string name);

        /**
         * Default for theme with dark mode
         */
        Theme();

        //basic getters

        std::string &GetName();

        std::string &GetFontColor();

        std::string &GetBackgroundColor();

    private:
        std::string background_color_;
        std::string font_color_;
        std::string name_;
    };
}

#endif //FINAL_PROJECT_THEME_H
