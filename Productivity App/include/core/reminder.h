//
// Created by asaho on 5/3/2021.
//

#ifndef FINAL_PROJECT_REMINDER_H
#define FINAL_PROJECT_REMINDER_H


#include <string>
#include <cinder/Timer.h>

namespace productivity {

    /**
     * Stores information for reminder objects
     */
    class Reminder {
    public:
        /**
         * Constructs a reminder object
         */
        Reminder();

        /**
         * Adds a letter to the end of the name of the reminder
         * @param letter the letter to be added
         */
        void AddToName(char letter);

        /**
         * Adds a number to the minute string which is then converted into a double
         * @param number the number to be added to minute string and converted
         */
        void AddToMinutes(char number);

        /**
         * Converts minutes to a string and returns the value
         * @return the value of minutes_ as a string
         */
        std::string GetMinutesString();

        /**
         * Sets minutes to a value based on a string
         * @param minutes the string to set minutes to
         */
        void SetMinutes(std::string &minutes);

        /**
         * Uses the timer to subtract time from the total minutes and stops and beeps if minutes_ is 0.
         */
        void SubtractTime();

        /**
         * Starts timer_
         */
        void StartTimer();

        //basic getters and setters

        void SetName(std::string &name);

        std::string GetName();

        double GetMinutes();

    private:
        std::string name_;
        double minutes_;
        std::string minutes_string_;
        cinder::Timer timer_;

        /**
         * Converts from string to double minutes_
         */
        void ConvertToMinutes();

        /**
         * Checks if minutes string is a number
         * @return true if is a number and false otherwise
         */
        bool isNumber();
    };
}


#endif //FINAL_PROJECT_REMINDER_H
