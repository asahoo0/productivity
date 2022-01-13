//
// Created by asaho on 4/20/2021.
//
#pragma once
#ifndef FINAL_PROJECT_HOME_PAGE_H
#define FINAL_PROJECT_HOME_PAGE_H

#include "cinder/gl/gl.h"

namespace productivity {
    /**
     * Stores information on how to draw the homepage.
     */
    class HomePage {
    public:

        /**
         * Takes input to know how many rows and cols to draw and draws based on screensize and margin
         * @param the margin between graphics.
         * @param the screensize of the window.
         */
        HomePage(float_t margin, float_t screenSize);

        /**
         * Default constructor with no input.
         */
        HomePage();

        /**
         * Draws the homepage.
         * @param color the color of the resources.
         */
        void Draw(const ci::ColorA &color);

        /**
         * Switches pages based on current_page_ variable.
         */
        int SwitchPage() const;

        /**
         * Adds a new page to pages_
         * @param page the name of the new page to by added
         */
        void AddPage(std::string page);

        /**
         * Changes the position of the box by changing the current page variable
         * @param change_by number to the pos by
         */
        void AddToPosition(int change_by);

    private:
        float_t margin_;
        float_t screen_size_;
        size_t current_page_;
        std::vector<std::string> pages_;

        /**
         * Draws a box around the change that would be selected if enter were to be pressed
         */
        void DrawBoxAroundCurrentPage() const;

    };
}


#endif //FINAL_PROJECT_HOME_PAGE_H
