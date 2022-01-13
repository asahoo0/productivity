#include <catch2/catch.hpp>
#include <visualizer/habit_page.h>

std::string sleep  = "sleep";

TEST_CASE("Add to Habit Streak") {
   productivity::HabitPage habit = productivity::HabitPage(840, 10);
   habit.AddNewHabit(sleep);
  SECTION("Position is inside the add box") {
        habit.AddToStreak(glm::vec2(564,6));
        REQUIRE(habit.GetStreak(0) == 1);
    }

  SECTION("Position is outside the add box") {
      habit.AddToStreak(glm::vec2(565,10));
      REQUIRE(habit.GetStreak(0) == 0);
    }

}

TEST_CASE("Reset Habit Streak") {
    productivity::HabitPage habit = productivity::HabitPage(840, 10);
    habit.AddNewHabit(sleep);
    habit.AddToStreak(glm::vec2(564,6));
    SECTION("Position is inside the reset box") {
        habit.ResetStreak(glm::vec2(571,6));
        REQUIRE(habit.GetStreak(0) == 0);
    }

    SECTION("Position is outside the reset box") {
        habit.ResetStreak(glm::vec2(570,6));
        REQUIRE(habit.GetStreak(0) == 1);
    }
}

TEST_CASE("Change Current Habit Name") {
    productivity::HabitPage habit = productivity::HabitPage(840, 10);
    habit.AddNewHabit(sleep);
    habit.AddToStreak(glm::vec2(564,6));

    SECTION("Add char to current habit") {
        habit.AddToCurrentHabitName('y');
        REQUIRE(habit.GetHabitName(0) == "sleepy");
    }

    SECTION("Backspace char from current habit") {
        habit.BackSpaceCurrentHabit();
        REQUIRE(habit.GetHabitName(0) == "slee");
    }
}