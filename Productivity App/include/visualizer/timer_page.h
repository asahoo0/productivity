//
// Created by asaho on 4/20/2021.
//
#pragma once
#ifndef FINAL_PROJECT_TIMER_PAGE_H
#define FINAL_PROJECT_TIMER_PAGE_H

#include <cinder/Timer.h>
#include "cinder/gl/gl.h"

namespace productivity {
    using glm::vec2;

    /**
     * Contains info on how to draw the timer page.
     */
    class TimerPage {
    public:
        /**
         * Takes in screen info to help draw the timer page.
         * @param screen_size the screen size.
         * @param margin the margin.
         */
        TimerPage(float_t screen_size, float_t margin, double_t add);

        /**
         * Default constructor with no input.
         */
        TimerPage();

        /**
         * Adds kAddTime to the remaining time.
         */
        void AddTimeRemaining();

        /**
         * Draws the timer page.
         * @param color the resources color.
         */
        void Draw(const cinder::ColorA color);

        /**
         * Toggles the timer between started and stopped.
         */
        void ToggleTimer();

        //getters

        double GetTimeRemaining();


    private:
        cinder::Timer timer_;
        double_t time_remaining_;
        double_t total_time_worked_;
        double_t add_time_ = 15;
        float_t screen_size_;
        float_t margin_;
    };
}


#endif //FINAL_PROJECT_TIMER_PAGE_H
