enum Pages {
    Home,
    Timer,
    HabitTracker,
    AllNotes,
    ToDoList,
    ReminderList,
    Customize,
    Instructions,
    Exit,
    Last,
    CurrentNote
};

//PagesList is used to assign strings to each page and last is used as a dummy stop point in home_page
class PagesList {
    static constexpr char *EnumStrings[] = {"Home", "Timer", "Habit Tracker", "Notes", "To Do", "Reminders",
                                            "Customize", "Instructions", "Exit"};
public:
    static const char *GetTextForEnum(int enumVal);
};