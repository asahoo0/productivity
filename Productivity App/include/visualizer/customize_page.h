//
// Created by asaho on 4/26/2021.
//

#pragma once
#ifndef FINAL_PROJECT_CUSTOMIZE_PAGE_H
#define FINAL_PROJECT_CUSTOMIZE_PAGE_H

#include <vector>
#include <glm/vec2.hpp>
#include <core/theme.h>
#include "cinder/gl/gl.h"


namespace productivity {
    /**
     * Holds,displays, and selects customization themes.
     */
    class CustomizePage {
    public:

        /**
         * Default constructor with no input.
         */
        CustomizePage();

        /**
         * Takes in screen size and margin for layout purposes.
         * @param margin the margin
         * @param screen_size the screen size
         */
        CustomizePage(float_t margin, float_t screen_size);

        /**
         * Draws the customize theme options
         * @param color the current color of resources
         */
        void Draw(const cinder::ColorA color);

        /**
         * Adds a new theme to the list
         * @param theme the theme being added
         */
        void AddTheme(Theme theme);

        /**
         * Sets the current position of the box used to select themes.
         * @param num how much to change the position of the box by.
         */
        void AddToPosition(int num);

        //basic getter
        Theme &GetSelectedTheme();


    private:
        float_t margin_;
        float_t screen_size_;
        size_t current_theme_;
        std::vector<Theme> themes_;

        /**
         * Draws a box around the theme that would be selected if return was hit right now.
         */
        void DrawBoxAroundCurrentTheme() const;
    };
}


#endif //FINAL_PROJECT_CUSTOMIZE_PAGE_H
