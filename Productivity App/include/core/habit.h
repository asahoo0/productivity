//
// Created by asaho on 4/20/2021.
//

#ifndef FINAL_PROJECT_HABIT_H
#define FINAL_PROJECT_HABIT_H


#include <string>

namespace productivity {
    /**
     * Creates a Habit Object with a string and associated integer.
     */
    class Habit {
    public:
        explicit Habit(std::string &habit);

        /**
         * Resets habit streak to 0.
         */
        void ResetHabitStreak();

        /**
         * Adds 1 to the habit streak.
         */
        void AddToHabitStreak();

        //basic getters and setters

        void SetHabit(std::string &habit_name);

        size_t GetHabitStreak() const;

        std::string &GetHabit();

    private:
        size_t habit_streak_ = 0;
        std::string habit_ = "";
    };
}


#endif //FINAL_PROJECT_HABIT_H
