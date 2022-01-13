//
// Created by asaho on 4/20/2021.
//

#include <Windows.h>
#include "visualizer/timer_page.h"

namespace productivity {
    using glm::vec2;

    TimerPage::TimerPage(float_t screen_size, float_t margin, double_t add) {
        time_remaining_ = 0;
        total_time_worked_ = 0;
        margin_ = margin;
        screen_size_ = screen_size;
        add_time_ = add;
    }

    void TimerPage::ToggleTimer() {
        if (time_remaining_ > 0 && timer_.isStopped()) {
            timer_.start();
        } else {
            timer_.stop();
        }
    }

    void TimerPage::Draw(const cinder::ColorA color) {
        if (time_remaining_ <= 0) {
            timer_.stop();
            time_remaining_ = 0;
        } else if (!timer_.isStopped()) {
            timer_.stop();
            time_remaining_ -= timer_.getSeconds();
            if (time_remaining_ <= 0) {
                Beep(523, 500);
                std::cin.get();
            }
            total_time_worked_ += timer_.getSeconds();
            timer_.start();
        }
        std::string time = std::to_string(time_remaining_);
        cinder::gl::drawString(time, vec2(screen_size_ / 2, screen_size_ / 2), color);
        std::string time_worked = "Time Worked: " + std::to_string(round(total_time_worked_) / 60) + " minutes";
        cinder::gl::drawString(time_worked, vec2(margin_, margin_), color);

    }

    void TimerPage::AddTimeRemaining() {
        time_remaining_ += add_time_;
    }

    TimerPage::TimerPage() {
        time_remaining_ = 0;
    }

    double TimerPage::GetTimeRemaining() {
        return time_remaining_;
    }
}
