//
// Created by asaho on 5/2/2021.
//

#include "visualizer/to_do_page.h"

namespace productivity {
    ToDoPage::ToDoPage() {
        current_pos_ = -1;
    }

    ToDoPage::ToDoPage(float_t margin, float_t screen_size) {
        current_pos_ = -1;
        screen_size_ = screen_size;
        margin_ = margin;
        find_mode_ = false;
        word_to_find_ = "";
        occurrence_ = 1;

    }

    void ToDoPage::AddNewToDo(const std::string &todo) {
        ToDo new_to_do = ToDo(todo);
        to_do_list_.push_back(new_to_do);
        current_pos_++;
    }

    void ToDoPage::AddToWordToFind(char letter) {
        word_to_find_ += letter;
    }

    void ToDoPage::BackSpaceToDo() {
        if (!to_do_list_.empty()) {
            std::string temp = to_do_list_.at(current_pos_).GetName().substr(0, to_do_list_.at(
                    current_pos_).GetName().size() - 1);
            to_do_list_.at(current_pos_).SetName(temp);
        }
    }

    void ToDoPage::BackSpaceWordToFind() {
        if (word_to_find_ != "") {
            word_to_find_ = word_to_find_.substr(0, word_to_find_.size() - 1);
        }
    }

    void ToDoPage::DrawToDoList(const cinder::ColorA color) {
        float_t position_of_text = margin_;
        for (size_t pos = 0; pos < to_do_list_.size(); pos++) {
            if (position_of_text < screen_size_) {
                std::string current_to_do = to_do_list_.at(current_pos_).GetName();
                int pos_word = FindStringInToDo();
                if (find_mode_ && current_pos_ == pos && pos_word != -1 && word_to_find_ != "") {
                    ci::gl::drawString(current_to_do.substr(0, pos_word) + "-" +
                                       current_to_do.substr(pos_word, (word_to_find_.size())) + "-" +
                                       current_to_do.substr(pos_word + word_to_find_.size()),
                                       glm::vec2(margin_, position_of_text), color);
                    ci::gl::drawString("Find: " + word_to_find_, glm::vec2(margin_, screen_size_ - margin_), color);
                } else {
                    ci::gl::drawString(to_do_list_.at(pos).GetName(), glm::vec2(margin_, position_of_text), color);
                    ci::gl::drawString("Find: " + word_to_find_, glm::vec2(margin_, screen_size_ - margin_), color);

                    if (to_do_list_.at(pos).GetIsCompleted()) {
                        ci::gl::drawString(ConvertToDashes(to_do_list_.at(pos).GetName().size()),
                                           glm::vec2(margin_, position_of_text), color);
                    }
                }
                position_of_text += 2 * margin_;
            }
        }
        DrawBoxAroundCurrentToDo();
    }

    void ToDoPage::AddToPosition(int num) {
        int temp = current_pos_ + num;
        if (temp >= 0 && temp < (int) to_do_list_.size()) {
            current_pos_ = temp;
        }
    }

    void ToDoPage::ToggleFindMode() {
        find_mode_ = !find_mode_;
    }

    void ToDoPage::AddToOccurrence(int num) {
        int temp = occurrence_ + num;
        if (temp >= 1) {
            occurrence_ = temp;
        }
    }

    bool ToDoPage::GetFindMode() const {
        return find_mode_;
    }

    void ToDoPage::AddToCurrentToDo(char letter) {
        if (!to_do_list_.empty()) {
            std::string to_do_name = to_do_list_.at(current_pos_).GetName() + letter;
            to_do_list_.at(current_pos_).SetName(to_do_name);
        }
    }

    void ToDoPage::DrawBoxAroundCurrentToDo() const {
        if (current_pos_ * 2 * margin_ < screen_size_) {
            ci::gl::drawStrokedRect(
                    ci::Rectf(margin_ / 2, margin_ / 2 + (current_pos_ * 2 * margin_), screen_size_,
                              2 * margin_ + (current_pos_ * 2 * margin_)));
        }
    }

    int ToDoPage::FindStringInToDo() {
        int pos = -1;
        int count = 0;
        std::string current_to_do = to_do_list_.at(current_pos_).GetName();

        while (count != occurrence_) {
            if (current_to_do.find(word_to_find_) != std::string::npos) {
                pos++;
                pos = current_to_do.find(word_to_find_, pos);
                count++;
            } else {
                occurrence_ = count;
                return pos;
            }
        }
        return pos;
    }

    std::string ToDoPage::ConvertToDashes(int length) {
        std::string dashes = "";
        while (length > 0) {
            dashes += "--";
            length--;
        }
        return dashes;
    }

    void ToDoPage::SetCurrentToDo() {
        if (!to_do_list_.empty()) {
            to_do_list_.at(current_pos_).ToggleIsCompleted();
        }
    }

    std::string ToDoPage::GetCurrentToDo() {
        return to_do_list_.at(current_pos_).GetName();
    }

    std::string ToDoPage::GetWordToFind() {
        return word_to_find_;
    }


}
