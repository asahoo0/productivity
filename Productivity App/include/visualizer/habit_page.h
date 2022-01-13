//
// Created by asaho on 4/20/2021.
//
#pragma once
#ifndef FINAL_PROJECT_HABIT_PAGE_H
#define FINAL_PROJECT_HABIT_PAGE_H


#include <vector>
#include <glm/vec2.hpp>
#include "core/habit.h"
#include "cinder/gl/gl.h"

namespace productivity {
    /**
     * Contains info on how to draw habit page.
     */
    class HabitPage {
    public:
        /**
         * Default constructor with no input.
         */
        HabitPage();

        /**
         * Takes in screen info to help draw the habit page.
         * @param window the screen size.
         * @param margin the margin.
         */
        HabitPage(float_t window, float_t margin);

        /**
         * Adds a new habit to the vector.
         * @param habit the string to be added that is the new habit.
         */
        void AddNewHabit(std::string& habit);

        /**
         * Adds a letter to the current habit.
         * @param letter the char to be added to the current habit.
         */
        void AddToCurrentHabitName(char letter);

        /**
         * Removes the last letter from the current habit.
         */
        void BackSpaceCurrentHabit();

        /**
         * Adds to streak for a habit if the pos is equal to habit green box pos.
         * @param pos the mouse click pos.
         */
        void AddToStreak(glm::vec2 pos);

        /**
         * Resets streak for a habit if the pos is equal to habit red box pos.
         * @param pos the mouse click pos.
         */
        void ResetStreak(glm::vec2 pos);

        /**
         * Draws the habit page.
         * @param color the color of the resources.
         */
        void Draw(const cinder::ColorA &color);

        /**
         * Gets the habit streak of the habit at pos.
         * @param pos the position of the habit.
         * @return the streak number.
         */
        size_t GetStreak(size_t pos);

        /**
         * Gets the habit name of the habit at pos.
         * @param pos the position of the habit name.
         * @return the habit name.
         */
        std::string GetHabitName(size_t pos);

    private:
        std::vector<Habit> habits_;
        int current_pos_;
        float_t screen_size_;
        float_t margin_;
    };
}

#endif //FINAL_PROJECT_HABIT_PAGE_H
