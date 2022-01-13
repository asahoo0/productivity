//
// Created by asaho on 5/2/2021.
//

#include "visualizer/instructions_page.h"

InstructionsPage::InstructionsPage() {
    margin_ = 0;
    screen_size_ = 0;
}

InstructionsPage::InstructionsPage(float_t margin, float_t screen_size) {
    margin_ = margin;
    screen_size_ = screen_size;
}

void InstructionsPage::Draw(const cinder::ColorA color) {
    ci::gl::drawString(kInstructions, glm::vec2(margin_, margin_), color); //draws instructions string
}
