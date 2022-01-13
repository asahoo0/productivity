#include <catch2/catch.hpp>
#include <visualizer/home_page.h>
#include <visualizer/timer_page.h>

TEST_CASE("Timer Add Test") {
    productivity::TimerPage timerPage = productivity::TimerPage(840, 10, 1);

    SECTION("Add 1 sec") {
        timerPage.AddTimeRemaining();
        REQUIRE(timerPage.GetTimeRemaining() == 1);
    }

    productivity::TimerPage timerPage2 = productivity::TimerPage(840, 10, 100);

    SECTION("Add 100 sec") {
        timerPage2.AddTimeRemaining();
        REQUIRE(timerPage2.GetTimeRemaining() == 100);
    }

    SECTION("Add multiple times") {
        timerPage.AddTimeRemaining();
        timerPage.AddTimeRemaining();
        timerPage.AddTimeRemaining();
        REQUIRE(timerPage.GetTimeRemaining() == 3);

        timerPage2.AddTimeRemaining();
        timerPage2.AddTimeRemaining();
        REQUIRE(timerPage2.GetTimeRemaining() == 200);
    }
}