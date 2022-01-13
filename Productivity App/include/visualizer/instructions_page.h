//
// Created by asaho on 5/2/2021.
//

#ifndef FINAL_PROJECT_INSTRUCTIONS_PAGE_H
#define FINAL_PROJECT_INSTRUCTIONS_PAGE_H


#include <string>
#include "cinder/gl/gl.h"

class InstructionsPage {
public:
    /**
     * Default Constructor for instructions
     */
    InstructionsPage();

    /**
     * Uses screen and margin to draw instructions
     * @param margin the margin
     * @param screen_size the screen size
     */
    InstructionsPage(float_t margin, float_t screen_size);

    void Draw(const cinder::ColorA color);

private:
    float_t margin_;
    float_t screen_size_;

    std::string kInstructions = "* Page 0: Home\n\n"
                                "  * Use up and down keys to scroll  \n\n"
                                "  * Use return to select a page\n\n"
                                "  * A reminder displays on home when time runs out for it\n\n"
                                "* Page 1: Timer\n\n"
                                "  * Use + key to add (not the equal using shift)\n\n"
                                "  * Use return to stop and start timer\n\n"
                                "  * Beeps when timer reaches 0 seconds\n\n"
                                "* Page 2: Habit Tracker\n\n"
                                "  * Use return to start typing a new habit\n\n"
                                "  * Use the green box to add 1 to the habit streak\n\n"
                                "  * Use the red box to reset the streak\n\n"
                                "* Page 3: Notes\n\n"
                                "  * Use + key to add s (not the equal using shift)\n\n"
                                "  * Use return to enter an existing note\n\n"
                                "  * Use up and down keys to navigate notes\n\n"
                                "  * CurrentNote:\n\n"
                                "      * Use RCTRL key to activate and deactivate find mode\n\n"
                                "      * Use right and left arrows to navigate all occurrences of the word to find\n\n"
                                "      * The word to find will be between two underscores\n\n"
                                "      * Use esc to go to AllNotes (Page 3)\n\n"
                                "* Page 4: To Do\n\n"
                                "  * Use + key to add to do items (not the equal using shift)\n\n"
                                "  * Use return to toggle the completion of an item\n\n"
                                "  * Use RCTRL key to activate and deactivate find mode\n\n"
                                "  * Use right and left arrows to navigate all occurrences of the word to find\n\n"
                                "  * The word to find will be between two dashes\n\n"
                                "* Page 5: Reminders\n\n"
                                "  * Use + key to add reminder (not the equal using shift) \n\n"
                                "  * Use RCTRL key to toggle between typing reminder name and time in minutes \n\n"
                                "  * Use up and down keys to navigate between reminders\n\n"
                                "  * Beeps when each reminder runs out of time and displays message on home\n\n"
                                "* Page 6: Customize\n\n"
                                "  * Use up and down keys to navigate different themes\n\n"
                                "  * Use return to select a theme\n\n"
                                "* Page 7: Instructions\n\n"
                                "  * Provides information on all the pages while running app\n\n"
                                "* Page 8: Exit\n\n"
                                "  * Use esc to enter the previous page and on Home to exit";

};


#endif //FINAL_PROJECT_INSTRUCTIONS_PAGE_H
