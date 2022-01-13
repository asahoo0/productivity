//
// Created by asaho on 5/2/2021.
//

#include "visualizer/reminder_page.h"

namespace productivity {

    ReminderPage::ReminderPage() {
        is_setting_minutes_ = false;
        current_pos_ = -1;
        margin_ = 0;
        screen_size_ = 0;
    }

    ReminderPage::ReminderPage(float_t margin, float_t screen_size) {
        is_setting_minutes_ = false;
        margin_ = margin;
        screen_size_ = screen_size;
        current_pos_ = -1;
    }

    void ReminderPage::AddToReminder(char reminder_part) {
        if (is_setting_minutes_) {
            reminder_list_.at(current_pos_).AddToMinutes(reminder_part);
        } else {
            reminder_list_.at(current_pos_).AddToName(reminder_part);
        }
    }

    void ReminderPage::CreateNewReminder() {
        Reminder reminder = Reminder();
        reminder_list_.push_back(reminder);
        current_pos_++;
        is_setting_minutes_ = false;
    }

    void ReminderPage::DrawReminderPage(const cinder::ColorA &color) {
        float_t position_of_text = margin_;
        if (!reminder_list_.empty()) {
            for (auto &pos : reminder_list_) {
                pos.SubtractTime();
                if (position_of_text < screen_size_) {
                    ci::gl::drawString(pos.GetName(), glm::vec2(margin_, position_of_text), color);
                    position_of_text += 2 * margin_;
                    std::string minutes = std::to_string(pos.GetMinutes());
                    ci::gl::drawString(minutes, glm::vec2(margin_, position_of_text), color);
                    position_of_text += 2 * margin_;
                }
            }
            DrawBoxAroundCurrentReminder();
        }
    }

    std::string ReminderPage::PopUpReminderOnScreen() {
        std::string name = "";
        if (!reminder_list_.empty()) {
            for (auto &pos : reminder_list_) {
                pos.SubtractTime();
                if (pos.GetMinutes() <= 0) {
                    name = pos.GetName();
                    return name;
                }
            }
        }
        return name;
    }

    void ReminderPage::ToggleIsSettingMinutes() {
        is_setting_minutes_ = !is_setting_minutes_;
    }

    void ReminderPage::DrawBoxAroundCurrentReminder() const {
        if (current_pos_ * 4 * margin_ < screen_size_) {
            ci::gl::drawStrokedRect(
                    ci::Rectf(margin_ / 2, margin_ / 2 + (current_pos_ * 4 * margin_), screen_size_,
                              4 * margin_ + (current_pos_ * 4 * margin_)));
        }
    }

    void ReminderPage::BackSpaceReminder() {
        if (!reminder_list_.empty()) {
            if (is_setting_minutes_) {
                std::string temp = reminder_list_.at(current_pos_).GetMinutesString().substr(0, reminder_list_.at(
                        current_pos_).GetMinutesString().size() - 1);
                reminder_list_.at(current_pos_).SetMinutes(temp);
            } else {
                std::string temp = reminder_list_.at(current_pos_).GetName().substr(0, reminder_list_.at(
                        current_pos_).GetName().size() - 1);
                reminder_list_.at(current_pos_).SetName(temp);
            }
        }
    }

    void ReminderPage::AddToPosition(int num) {
        int temp = current_pos_ + num;
        if (temp >= 0 && temp < (int) reminder_list_.size()) {
            current_pos_ = temp;
        }
    }

    void ReminderPage::StartReminder() {
        if (!reminder_list_.empty()) {
            reminder_list_.at(current_pos_).StartTimer();
        }
    }

    int ReminderPage::GetPosition() {
        return current_pos_;
    }
}