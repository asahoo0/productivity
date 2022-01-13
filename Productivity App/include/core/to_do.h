//
// Created by asaho on 5/1/2021.
//

#ifndef FINAL_PROJECT_TO_DO_H
#define FINAL_PROJECT_TO_DO_H

#include <string>

namespace productivity {
    /**
     * Creates a To Do Object with a name and a completion boolean
     */
    class ToDo {
    public:

        /**
         * Initializes a to do object
         * @param name the name of the to-do object
         */
        ToDo(std::string name);

        /**
         * Sets toggle is completed to its opposite.
         */
        void ToggleIsCompleted();

        //getters and setters

        std::string GetName();

        void SetName(std::string item);

        bool GetIsCompleted();

    private:
        bool is_completed_;
        std::string name_;

    };
}


#endif //FINAL_PROJECT_TO_DO_H
