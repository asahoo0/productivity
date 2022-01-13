//
// Created by asaho on 4/20/2021.
//

#include "visualizer/home_page.h"

namespace productivity {
    HomePage::HomePage(float_t margin, float_t screenSize) {
        screen_size_ = screenSize;
        margin_ = margin;
        current_page_ = 0;
    }

    void HomePage::Draw(const ci::ColorA &color) {
        float_t position_of_text = margin_;
        if (!pages_.empty()) {
            for (auto &pos : pages_) { //loops through and draws all the pages on home screen
                if (position_of_text < screen_size_) {
                    ci::gl::drawString(pos, glm::vec2(margin_, position_of_text), color);
                    position_of_text += 2 * margin_;
                }
            }
            DrawBoxAroundCurrentPage();
        }

    }

    void HomePage::DrawBoxAroundCurrentPage() const {
        if (current_page_ * 2 * margin_ < screen_size_) {
            ci::gl::drawStrokedRect(
                    ci::Rectf(margin_ / 2, margin_ / 2 + (current_page_ * 2 * margin_), screen_size_,
                              2 * margin_ + (current_page_ * 2 * margin_)));
        }
    }

    int HomePage::SwitchPage() const {
        return current_page_;
    }

    HomePage::HomePage() {
        margin_ = 0;
        screen_size_ = 0;
        current_page_ = 0;
    }

    void HomePage::AddPage(std::string page) {
        pages_.push_back(page);
    }

    void HomePage::AddToPosition(int num) {
        int temp = current_page_ + num;
        if (temp >= 0 && temp < (int) pages_.size()) {
            current_page_ = temp;
        }
    }
}
