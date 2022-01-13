//
// Created by asaho on 4/20/2021.
//

#include "core/habit.h"

void productivity::Habit::SetHabit(std::string &habit_name) {
    habit_ = habit_name;
}

void productivity::Habit::ResetHabitStreak() {
    habit_streak_ = 0;
}

void productivity::Habit::AddToHabitStreak() {
    habit_streak_ += 1;
}

size_t productivity::Habit::GetHabitStreak() const {
    return habit_streak_;
}

std::string &productivity::Habit::GetHabit() {
    return habit_;
}

productivity::Habit::Habit(std::string &habit) {
    habit_ = habit;
}
