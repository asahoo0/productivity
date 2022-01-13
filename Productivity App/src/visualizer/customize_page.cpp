//
// Created by asaho on 4/26/2021.
//

#include "visualizer/customize_page.h"

namespace productivity {

    CustomizePage::CustomizePage() {
        margin_ = 10;
        screen_size_ = 840;
    }

    CustomizePage::CustomizePage(float_t margin, float_t screen_size) {
        margin_ = margin;
        screen_size_ = screen_size;
        Theme dark = Theme("black", "white", "dark");
        themes_.push_back(dark);
        current_theme_ = 0;
    }

    void CustomizePage::Draw(const cinder::ColorA color) {
        float_t position_of_text = margin_;
        if (!themes_.empty()) {
            for (auto &pos : themes_) {
                if (position_of_text < screen_size_) {
                    //draws each string with same x and different y pos
                    ci::gl::drawString(pos.GetName(), glm::vec2(margin_, position_of_text), color);
                    position_of_text += 2 * margin_;
                }
            }
            DrawBoxAroundCurrentTheme();
        }
    }

    void CustomizePage::DrawBoxAroundCurrentTheme() const {
        if (current_theme_ * 2 * margin_ < screen_size_) {
            ci::gl::drawStrokedRect(
                    ci::Rectf(margin_ / 2, margin_ / 2 + (current_theme_ * 2 * margin_), screen_size_,
                              2 * margin_ + (current_theme_ * 2 * margin_)));
        }
    }

    void CustomizePage::AddToPosition(int num) {
        int temp = current_theme_ + num;
        if (temp >= 0 && temp < (int) themes_.size()) {
            current_theme_ = temp;
        }
    }

    void CustomizePage::AddTheme(Theme theme) {
        themes_.push_back(theme);
    }

    Theme &CustomizePage::GetSelectedTheme() {
        return themes_.at(current_theme_);
    }
}
