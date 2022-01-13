#include <visualizer/productivity_app.h>

namespace productivity {

    ProductivityApp::ProductivityApp() {
        ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

        home_page_ = HomePage(kMargin, kWindowSize);
        AddPages();

        customize_page_ = CustomizePage(kMargin, kWindowSize);
        AddThemes();

        timer_page_ = TimerPage(kWindowSize, kMargin, 5);
        habit_page_ = HabitPage(kWindowSize, kMargin);
        note_page_ = NotesPage(kMargin, kWindowSize);
        to_do_page_ = ToDoPage(kMargin, kWindowSize);
        reminder_page_ = ReminderPage(kMargin, kWindowSize);

        current_screen_ = Home;
        current_theme_ = customize_page_.GetSelectedTheme();
    }


    void ProductivityApp::draw() {
        //background color
        std::string color = current_theme_.GetBackgroundColor();
        const char *c = color.c_str();
        const cinder::ColorA &background_color = cinder::ColorA(c);
        ci::gl::clear(background_color, true);

        //font color
        color = current_theme_.GetFontColor();
        c = color.c_str();
        const cinder::ColorA &font_color = cinder::ColorA(c);
        ci::gl::color(font_color);

        //selects what screen to draw
        if (current_screen_ == Home) {
            home_page_.Draw(font_color);
            //Reminder on home page
            ci::gl::drawString("Reminder:" + reminder_page_.PopUpReminderOnScreen(),
                               glm::vec2(kMargin, kWindowSize - kMargin), font_color);
        } else if (current_screen_ == Timer) {
            timer_page_.Draw(font_color);
        } else if (current_screen_ == HabitTracker) {
            habit_page_.Draw(font_color);
        } else if (current_screen_ == AllNotes) {
            note_page_.DrawAllNotes(font_color);
        } else if (current_screen_ == CurrentNote) {
            note_page_.DrawCurrentNote(font_color);
        } else if (current_screen_ == Customize) {
            customize_page_.Draw(font_color);
        } else if (current_screen_ == ToDoList) {
            to_do_page_.DrawToDoList(font_color);
        } else if (current_screen_ == ReminderList) {
            reminder_page_.DrawReminderPage(font_color);
        } else if (current_screen_ == Instructions) {
            instructions_page_.Draw(font_color);
        } else {
            quit();
        }
    }

    void ProductivityApp::mouseDown(ci::app::MouseEvent event) {
        if (current_screen_ == HabitTracker) {
            habit_page_.AddToStreak(event.getPos());
            habit_page_.ResetStreak(event.getPos());
        }
    }

    void ProductivityApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_KP_PLUS: {
                if (current_screen_ == Timer) {
                    timer_page_.AddTimeRemaining();
                }

                if (current_screen_ == AllNotes) {
                    note_page_.AddNewNote("");
                    current_screen_ = CurrentNote;
                }

                if (current_screen_ == ToDoList) {
                    to_do_page_.AddNewToDo("");
                }

                if (current_screen_ == ReminderList) {
                    reminder_page_.CreateNewReminder();
                }
            }
                break;

            case ci::app::KeyEvent::KEY_UP: {
                if (current_screen_ == AllNotes) {
                    note_page_.AddToPosition(-1);
                }

                if (current_screen_ == ToDoList) {
                    to_do_page_.AddToPosition(-1);
                }

                if (current_screen_ == Home) {
                    home_page_.AddToPosition(-1);
                }

                if (current_screen_ == Customize) {
                    customize_page_.AddToPosition(-1);
                }

                if (current_screen_ == ReminderList) {
                    reminder_page_.AddToPosition(-1);
                }
            }
                break;

            case ci::app::KeyEvent::KEY_DOWN: {
                if (current_screen_ == AllNotes) {
                    note_page_.AddToPosition(1);
                }

                if (current_screen_ == Home) {
                    home_page_.AddToPosition(1);
                }

                if (current_screen_ == ToDoList) {
                    to_do_page_.AddToPosition(1);
                }

                if (current_screen_ == Customize) {
                    customize_page_.AddToPosition(1);
                }

                if (current_screen_ == ReminderList) {
                    reminder_page_.AddToPosition(1);
                }
            }
                break;

            case ci::app::KeyEvent::KEY_RIGHT: {
                if (current_screen_ == CurrentNote && note_page_.GetFindMode()) {
                    note_page_.AddToOccurrence(1);
                } else if (current_screen_ == ToDoList && to_do_page_.GetFindMode()) {
                    to_do_page_.AddToOccurrence(1);
                }
            }
                break;

            case ci::app::KeyEvent::KEY_LEFT: {
                if (current_screen_ == CurrentNote && note_page_.GetFindMode()) {
                    note_page_.AddToOccurrence(-1);
                } else if (current_screen_ == ToDoList && to_do_page_.GetFindMode()) {
                    to_do_page_.AddToOccurrence(-1);
                }
            }
                break;

            case ci::app::KeyEvent::KEY_RETURN: {
                if (current_screen_ == Timer) {
                    timer_page_.ToggleTimer();
                }
                if (current_screen_ == HabitTracker) {
                    std::string habit = "";
                    habit_page_.AddNewHabit(habit);
                }

                if (current_screen_ == AllNotes) {
                    current_screen_ = CurrentNote;
                }

                if (current_screen_ == Customize) {
                    current_theme_ = customize_page_.GetSelectedTheme();
                }

                if (current_screen_ == Home) {
                    current_screen_ = (Pages) home_page_.SwitchPage();
                }

                if (current_screen_ == ToDoList) {
                    to_do_page_.SetCurrentToDo();
                }

                if (current_screen_ == ReminderList) {
                    reminder_page_.StartReminder();
                }

            }
                break;

            case ci::app::KeyEvent::KEY_BACKSPACE: {
                if (current_screen_ == HabitTracker) {
                    habit_page_.BackSpaceCurrentHabit();
                } else if (current_screen_ == CurrentNote && !note_page_.GetFindMode()) {
                    note_page_.BackSpaceCurrentNote();
                } else if (current_screen_ == CurrentNote && note_page_.GetFindMode()) {
                    note_page_.BackSpaceWordToFind();
                } else if (current_screen_ == ToDoList && to_do_page_.GetFindMode()) {
                    to_do_page_.BackSpaceWordToFind();
                } else if (current_screen_ == ToDoList && !to_do_page_.GetFindMode()) {
                    to_do_page_.BackSpaceToDo();
                } else if (current_screen_ == ReminderList) {
                    reminder_page_.BackSpaceReminder();
                }
            }
                break;

            case ci::app::KeyEvent::KEY_RCTRL: {
                if (current_screen_ == CurrentNote) {
                    note_page_.ToggleFindMode();
                } else if (current_screen_ == ToDoList) {
                    to_do_page_.ToggleFindMode();
                }

                if (current_screen_ == ReminderList) {
                    reminder_page_.ToggleIsSettingMinutes();
                }
            }
                break;

            case ci::app::KeyEvent::KEY_ESCAPE: {
                switch (current_screen_) {
                    case 0:
                        quit();
                    default:
                        if (current_screen_ == CurrentNote) {
                            current_screen_ = AllNotes;
                        } else {
                            current_screen_ = Home;
                        }

                }
            }
            default:
                //adds letter to a string
                if (current_screen_ == HabitTracker) {
                    habit_page_.AddToCurrentHabitName(event.getChar());
                } else if (current_screen_ == CurrentNote && !note_page_.GetFindMode()) {
                    note_page_.AddToCurrentNote(event.getChar());
                } else if (current_screen_ == CurrentNote && note_page_.GetFindMode()) {
                    note_page_.AddToWordToFind(event.getChar());
                } else if (current_screen_ == ToDoList && !to_do_page_.GetFindMode()) {
                    to_do_page_.AddToCurrentToDo(event.getChar());
                } else if (current_screen_ == ToDoList && to_do_page_.GetFindMode()) {
                    to_do_page_.AddToWordToFind(event.getChar());
                } else if (current_screen_ == ReminderList) {
                    reminder_page_.AddToReminder(event.getChar());
                }
        }
    }

    void ProductivityApp::AddThemes() {
        std::vector<Theme> themes;
        themes.push_back(Theme("white", "black", "light"));
        themes.push_back(Theme("brown", "green", "earthy"));

        for (const Theme &theme : themes) {
            customize_page_.AddTheme(theme);
        }
    }

    void ProductivityApp::AddPages() {
        for (int page = Home; page != Last; page++) {
            home_page_.AddPage(static_cast<std::string>(PagesList::GetTextForEnum(page)));
        }
    }
}  // namespace productivity
