//
// Created by asaho on 4/20/2021.
//

#include "visualizer/habit_page.h"

namespace productivity {

    HabitPage::HabitPage() {
        margin_ = 0;
        screen_size_ = 0;
        current_pos_ = -1;
    }

    HabitPage::HabitPage(float_t window, float_t margin) {
        current_pos_ = -1;
        screen_size_ = window;
        margin_ = margin;
    }

    void HabitPage::AddNewHabit(std::string &habit) {
        Habit new_habit = Habit(habit);
        habits_.push_back(new_habit);
        current_pos_++;
    }

    void HabitPage::AddToCurrentHabitName(char letter) {
        if (!habits_.empty()) {
            std::string habit_name = habits_.at(current_pos_).GetHabit() + letter;
            habits_.at(current_pos_).SetHabit(habit_name);
        }
    }

    void HabitPage::AddToStreak(glm::vec2 click_pos) {
        float_t position_of_text = margin_;
        for (auto &habit : habits_) {
            if (position_of_text < screen_size_ && !habit.GetHabit().empty()) {
                //uses green box pos to determine if the user clicked it
                if (click_pos.x > 2 * screen_size_ / 3 - margin_ / 2 &&
                    click_pos.x < 2 * screen_size_ / 3 + margin_ / 2) {
                    if (click_pos.y > position_of_text - margin_ / 2 && click_pos.y < position_of_text + margin_ / 2) {
                        habit.AddToHabitStreak();
                    }
                }
                position_of_text += 2 * margin_;
            }
        }
    }

    void HabitPage::ResetStreak(glm::vec2 click_pos) {//use position of box
        float_t position_of_text = margin_;
        for (auto &habit : habits_) {
            if (position_of_text < screen_size_ && !habit.GetHabit().empty()) {
                //uses red box pos to determine if user clicked it
                if (click_pos.x > 2 * screen_size_ / 3 + margin_ && click_pos.x < 2 * screen_size_ / 3 + 2 * margin_) {
                    if (click_pos.y > position_of_text - margin_ / 2 && click_pos.y < position_of_text + margin_ / 2) {
                        habit.ResetHabitStreak();
                    }
                }
                position_of_text += 2 * margin_;
            }
        }
    }


    void HabitPage::Draw(const cinder::ColorA &color) {
        float_t position_of_text = margin_;
        for (auto &habit : habits_) {
            if (position_of_text < screen_size_ && !habit.GetHabit().empty()) {
                //habit name
                std::string temp = habit.GetHabit() + " " + std::to_string(habit.GetHabitStreak());
                ci::gl::drawString(temp, glm::vec2(screen_size_ / 3, position_of_text), color);

                ci::gl::color(0, 1, 0); //green box
                ci::gl::drawSolidRect(ci::Rectf(2 * screen_size_ / 3 - margin_ / 2, position_of_text - margin_ / 2,
                                                2 * screen_size_ / 3 + margin_ / 2, position_of_text + margin_ / 2));

                ci::gl::color(1, 0, 0); //red box
                ci::gl::drawSolidRect(ci::Rectf(2 * screen_size_ / 3 + margin_, position_of_text - margin_ / 2,
                                                2 * screen_size_ / 3 + 2 * margin_, position_of_text + margin_ / 2));

                position_of_text += 2 * margin_;
                ci::gl::color(1, 1, 1); //resets color
            }
        }
    }

    void HabitPage::BackSpaceCurrentHabit() {
        if (!habits_.empty()) {
            //use substring to eliminate the final char in a string
            std::string temp = habits_.at(current_pos_).GetHabit().substr(0,
                                                                          habits_.at(current_pos_).GetHabit().size() -
                                                                          1);
            habits_.at(current_pos_).SetHabit(temp);
        }
    }

    size_t HabitPage::GetStreak(size_t pos) {
        return habits_.at(pos).GetHabitStreak();
    }

    std::string HabitPage::GetHabitName(size_t pos) {
        return habits_.at(pos).GetHabit();
    }
}