//
// Created by asaho on 4/25/2021.
//

#ifndef FINAL_PROJECT_NOTES_PAGE_H
#define FINAL_PROJECT_NOTES_PAGE_H
#pragma once

#include <vector>
#include <glm/vec2.hpp>
#include "cinder/gl/gl.h"


namespace productivity {
    /**
     * Contains the AllNotes and CurrentNote Pages
     */
    class NotesPage {
    public:

        /**
         * Default constructor for NotesPage
         */
        NotesPage();

        /**
         * NotesPage constructor that adjusts for screen and margin.
         * @param margin the margin
         * @param screen_size the screen size,
         */
        NotesPage(float_t margin, float_t screen_size);

        /**
         * Adds a new note to the note list
         * @param note the newlt created note.
         */
        void AddNewNote(const std::string &note);

        /**
         * Adds a letter to the current note.
         * @param letter the letter to be added.
         */
        void AddToCurrentNote(char letter);

        /**
         * Adds a letter to the word to find.
         * @param letter the letter to be added.
         */
        void AddToWordToFind(char letter);

        /**
         * Deletes the last letter of the current note
         */
        void BackSpaceCurrentNote();

        /**
         * Deletes the last letter of the word to find.
         */
        void BackSpaceWordToFind();

        /**
         * Draws all notes in the list
         * @param color the resources color
         */
        void DrawAllNotes(const cinder::ColorA& color);

        /**
         * Draws the current note
         * @param color the resources color
         */
        void DrawCurrentNote(const cinder::ColorA color);

        /**
         * Adds to the current position to change current note in list.
         * @param num the int added by.
         */
        void AddToPosition(int num);

        /**
         * Turns Find Mode on and off in current note.
         */
        void ToggleFindMode();

        /**
         * Adds to the occurrence we are currently looking for
         * @param num the int added by
         */
        void AddToOccurrence(int num);

        //basic getters
        bool GetFindMode() const;

        std::string GetWordToFind();

        std::string GetCurrentNote();

    private:
        std::vector<std::string> note_list_;
        std::string word_to_find_;
        int current_pos_;
        float_t margin_;
        float_t screen_size_;
        bool find_mode_;
        int occurrence_; //occurrence we are looking for


        /**
         * Draws a box around the note that would be selected if return was hit right now.
         */
        void DrawBoxAroundCurrentNote() const;

        /**
         * Finds the position of a string in current note based on occurrence number.
         * @return int the pos of the word to find that matches the occurrence number
         */
        int FindStringInCurrentNote();
    };
}

#endif //FINAL_PROJECT_NOTES_PAGE_H
