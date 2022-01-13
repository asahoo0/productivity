//
// Created by asaho on 4/25/2021.
//

#ifndef FINAL_PROJECT_TO_DO_PAGE_H
#define FINAL_PROJECT_TO_DO_PAGE_H
#pragma once

#include <vector>
#include <glm/vec2.hpp>
#include <core/to_do.h>
#include "cinder/gl/gl.h"


namespace productivity {
    /**
     * Contains the ToDoList Page
     */
    class ToDoPage {
    public:

        /**
         * Default constructor for ToDoPage
         */
        ToDoPage();

        /**
         * ToDoPage constructor that adjusts for screen and margin.
         * @param margin the margin
         * @param screen_size the screen size,
         */
        ToDoPage(float_t margin, float_t screen_size);

        /**
         * Adds a char to the current to do string
         * @param the letter to be added to the to do string.
         */
        void AddToCurrentToDo(char letter);

        /**
         * Adds a new to do to the to do list
         * @param to do the newly created to do.
         */
        void AddNewToDo(const std::string& todo);

        /**
         * Adds a letter to the word to find.
         * @param letter the letter to be added.
         */
        void AddToWordToFind(char letter);

        /**
         * Deletes the last letter of the current to do
         */
        void BackSpaceToDo();

        /**
         * Deletes the last letter of the word to find.
         */
        void BackSpaceWordToFind();

        /**
         * Draws todos in the list
         * @param color the resources color
         */
        void DrawToDoList(const cinder::ColorA color);

        /**
         * Adds to the current position to change current to do in list.
         * @param num the int added by.
         */
        void AddToPosition(int num);

        /**
         * Turns Find Mode on and off in current to do.
         */
        void ToggleFindMode();

        /**
         * Adds to the occurrence we are currently looking for
         * @param num the int added by
         */
        void AddToOccurrence(int num);

        /**
         * Switches the current to do list to the opposite of its current completion state
         */
        void SetCurrentToDo();

        //basic find_mode_ getter
        bool GetFindMode() const;

        std::string GetCurrentToDo();

        std::string GetWordToFind();

    private:
        std::vector<ToDo> to_do_list_;
        std::string word_to_find_;
        int current_pos_;
        float_t margin_;
        float_t screen_size_;
        bool find_mode_;
        int occurrence_; //occurrence we are looking for


        /**
         * Draws a box around the note that would be selected if return was hit right now.
         */
        void DrawBoxAroundCurrentToDo() const;

        /**
         * Finds the position of a string in current note based on occurrence number.
         * @return int the pos of the word to find that matches the occurrence number
         */
        int FindStringInToDo();

        /**
         * Adds dashes to a string and returns it.
         * @param length the length of a string to convert to dashes
         * @return a string of dashes
         */
        std::string ConvertToDashes(int length);
    };
}

#endif //FINAL_PROJECT_TO_DO_PAGE_H
