//
// Created by asaho on 4/25/2021.
//

#include "visualizer/notes_page.h"

namespace productivity {

    NotesPage::NotesPage() {
        current_pos_ = -1;
    }

    NotesPage::NotesPage(float_t margin, float_t screen_size) {
        screen_size_ = screen_size;
        margin_ = margin;
        current_pos_ = -1;
        find_mode_ = false;
        word_to_find_ = "";
        occurrence_ = 1;
    }

    void NotesPage::AddNewNote(const std::string &note) {
        note_list_.push_back(note);
        current_pos_++;
    }

    void NotesPage::DrawAllNotes(const cinder::ColorA& color) {
        float_t position_of_text = margin_;
        if (!note_list_.empty()) {
            for (auto &pos : note_list_) { //draws all notes in the list
                if (position_of_text < screen_size_) {
                    ci::gl::drawString(pos, glm::vec2(margin_, position_of_text), color);
                    position_of_text += 2 * margin_;
                }
            }
            DrawBoxAroundCurrentNote();
        }
    }

    void NotesPage::DrawCurrentNote(const cinder::ColorA color) {
        std::string current_note = note_list_.at(current_pos_);
        int pos = FindStringInCurrentNote();
        if (!word_to_find_.empty() && find_mode_ && pos != -1) {
            //find feature
            ci::gl::drawString(
                    current_note.substr(0, pos) + "_" + current_note.substr(pos, (word_to_find_.size())) + "_" +
                    current_note.substr(pos + word_to_find_.size()), glm::vec2(screen_size_ / 3, margin_), color);
            ci::gl::drawString("Find: " + word_to_find_, glm::vec2(margin_, screen_size_ - margin_), color);
        } else {
            //if word not found or not in find mode
            ci::gl::drawString(note_list_.at(current_pos_), glm::vec2(screen_size_ / 3, margin_), color);
            ci::gl::drawString("Find: " + word_to_find_, glm::vec2(margin_, screen_size_ - margin_), color);
        }
    }

    void NotesPage::AddToPosition(int num) {
        int temp = current_pos_ + num;
        if (temp >= 0 && temp < (int) note_list_.size()) {
            current_pos_ = temp;
        }
    }

    void NotesPage::AddToOccurrence(int num) {
        int temp = occurrence_ + num;
        if (temp >= 1) {
            occurrence_ = temp;
        }
    }

    void NotesPage::AddToCurrentNote(char letter) {
        if (!note_list_.empty() && !find_mode_) {
            note_list_.at(current_pos_) = note_list_.at(current_pos_) + letter;
        }
    }

    void NotesPage::BackSpaceCurrentNote() {
        if (!note_list_.empty() && !find_mode_) {
            std::string temp = note_list_.at(current_pos_).substr(0, note_list_.at(current_pos_).size() - 1);
            note_list_.at(current_pos_) = temp;
        }
    }

    void NotesPage::DrawBoxAroundCurrentNote() const {
        if (current_pos_ * 2 * margin_ < screen_size_) {
            ci::gl::drawStrokedRect(
                    ci::Rectf(margin_ / 2, margin_ / 2 + (current_pos_ * 2 * margin_), screen_size_,
                              2 * margin_ + (current_pos_ * 2 * margin_)));
        }
    }

    void NotesPage::ToggleFindMode() {
        find_mode_ = !find_mode_;
    }

    bool NotesPage::GetFindMode() const {
        return find_mode_;
    }

    void NotesPage::BackSpaceWordToFind() {
        if (word_to_find_ != "") {
            word_to_find_ = word_to_find_.substr(0, word_to_find_.size() - 1);
        }
    }

    void NotesPage::AddToWordToFind(char letter) {
        word_to_find_ += letter;
    }

    int NotesPage::FindStringInCurrentNote() {
        int pos = -1;
        int count = 0;
        std::string current_note = note_list_.at(current_pos_);

        while (count != occurrence_) { //finds the correct occurrence of a string
            if (current_note.find(word_to_find_) != std::string::npos) {
                pos++;
                pos = current_note.find(word_to_find_, pos); //checks and finds next position of word in string
                count++;
            } else {
                occurrence_ = count; //no more occurrences of word
                return pos;
            }
        }
        return pos;
    }

    std::string NotesPage::GetWordToFind() {
        return word_to_find_;
    }

    std::string NotesPage::GetCurrentNote() {
        return note_list_.at(current_pos_);
    }
}
