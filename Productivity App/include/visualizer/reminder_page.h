//
// Created by asaho on 5/2/2021.
//

#ifndef FINAL_PROJECT_CALENDAR_PAGE_H
#define FINAL_PROJECT_CALENDAR_PAGE_H
#pragma once

#include <vector>
#include <core/reminder.h>
#include <glm/vec2.hpp>
#include "cinder/gl/gl.h"

namespace productivity {

    /**
     * Contains display information and functionality for the reminders page
     */
    class ReminderPage {

    public:

        /**
         * Default constructor for reminder page
         */
        ReminderPage();

        /**
         * Sets up reminder page based on screen and margin
         * @param margin the margin
         * @param screen_size the screen size
         */
        ReminderPage(float_t margin, float_t screen_size);

        /**
         * Adds to the current reminder's name or minutes
         * @param reminder_part the char to be added to the reminder's name or minutes
         */
        void AddToReminder(char reminder_part);

        /**
         * Adds a new blank reminder to the reminder list
         */
        void CreateNewReminder();

        /**
         * Draws the reminder page
         * @param color the font color
         */
        void DrawReminderPage(const cinder::ColorA &color);

        /**
         * Pops up latest reminder in which the timer runs out
         * @return the name of the reminder to be popped up on the home screen
         */
        std::string PopUpReminderOnScreen();

        /**
         * Toggles the value for the boolean is setting minutes
         */
        void ToggleIsSettingMinutes();

        /**
         * Backspaces the current reminder's name or minutes based to is setting minutes boolean
         */
        void BackSpaceReminder();

        /**
         * Adds to the current pos in reminder list
         * @param num the num to be added by
         */
        void AddToPosition(int num);

        /**
         * Starts the timer for the current reminder
         */
        void StartReminder();

        //getter
        int GetPosition();

    private:
        std::vector<Reminder> reminder_list_;
        bool is_setting_minutes_;
        float_t margin_;
        float_t screen_size_;
        int current_pos_;

        /**
         * Draw box around the currently editing reminder
         */
        void DrawBoxAroundCurrentReminder() const;
    };
}


#endif //FINAL_PROJECT_CALENDAR_PAGE_H
