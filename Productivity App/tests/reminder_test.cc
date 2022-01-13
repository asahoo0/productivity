#include <catch2/catch.hpp>
#include <visualizer/reminder_page.h>

TEST_CASE("Convert from string to double") {
    productivity::Reminder reminder = productivity::Reminder();
    std::string num = "hi";
    SECTION("Not a number string") {
        reminder.SetMinutes(num);
        REQUIRE(reminder.GetMinutes() == 0);
    }

    SECTION("Number string") {
        num = "2";
        reminder.SetMinutes(num);
        REQUIRE(reminder.GetMinutes() == 2);
    }
}

TEST_CASE("Change current pos") {
    productivity::ReminderPage reminder = productivity::ReminderPage(10, 840);
    reminder.CreateNewReminder();
    reminder.CreateNewReminder();

    SECTION("Position Not be Negative") {
        reminder.AddToPosition(-1);
        REQUIRE(reminder.GetPosition() == 0);
    }

    SECTION("Position cannot be greater than pages list size") {
        reminder.AddToPosition(1);
        reminder.AddToPosition(1);
        REQUIRE(reminder.GetPosition() == 1);
    }

    SECTION("Position Can be Added") {
        reminder.AddToPosition(1);
        REQUIRE(reminder.GetPosition() == 1);
    }

    SECTION("Position Can be Subtracted") {
        reminder.AddToPosition(1);
        reminder.AddToPosition(-1);
        REQUIRE(reminder.GetPosition() == 0);
    }

}