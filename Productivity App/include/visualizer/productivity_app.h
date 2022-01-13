#pragma once

#include <core/pages.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "timer_page.h"
#include "home_page.h"
#include "habit_page.h"
#include "notes_page.h"
#include "customize_page.h"
#include "to_do_page.h"
#include "reminder_page.h"
#include "instructions_page.h"

namespace productivity {


/**
 * Runner for the productivity app.
 */
    class ProductivityApp : public ci::app::App {
    public:
        /**
         * Constructs a window and graphics for each page.
         */
        ProductivityApp();

        /**
         * Draws the app based on current page.
         */
        void draw() override;

        /**
         * Performs actions based on mouse click.
         * @param event the mouse click event.
         */
        void mouseDown(ci::app::MouseEvent event) override;

        /**
         * Performs actions based on key click.
         * @param event the key click event.
         */
        void keyDown(ci::app::KeyEvent event) override;

        const float kWindowSize = 840;
        const float kMargin = 10;

    private:
        TimerPage timer_page_;
        HomePage home_page_;
        HabitPage habit_page_;
        CustomizePage customize_page_;
        NotesPage note_page_;
        Theme current_theme_;
        ToDoPage to_do_page_;
        ReminderPage reminder_page_;
        InstructionsPage instructions_page_;
        Pages current_screen_;

        /**
         * Adds new themes to customize page
         */
        void AddThemes();

        /**
         * Adds new pages to home page
         */
        void AddPages();
    };


}  // namespace naivebayes
