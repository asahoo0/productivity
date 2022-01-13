#include <catch2/catch.hpp>
#include <visualizer/home_page.h>

TEST_CASE("Changes to current pos") {
    productivity::HomePage home = productivity::HomePage(10, 840);
    home.AddPage("page1");
    home.AddPage("page2");

    SECTION("Position Cannot be Negative") {
        home.AddToPosition(-1);
        REQUIRE(home.SwitchPage() == 0);
    }

    SECTION("Position can't be greater than pages list size") {
        home.AddToPosition(1);
        home.AddToPosition(1);
        REQUIRE(home.SwitchPage() == 1);
    }

    SECTION("Position Can be Added To") {
        home.AddToPosition(1);
        REQUIRE(home.SwitchPage() == 1);
    }

    SECTION("Position Can be Subtracted From") {
        home.AddToPosition(1);
        home.AddToPosition(-1);
        REQUIRE(home.SwitchPage() == 0);
    }

}

TEST_CASE("Switch Page") {
    productivity::HomePage home = productivity::HomePage(10, 840);
    home.AddPage("page1");
    home.AddPage("page2");
    home.AddPage("page3");

    SECTION("Switch to first page") {
        REQUIRE(home.SwitchPage() == 0);
    }

    SECTION("Switch to last page") {
        home.AddToPosition(1);
        home.AddToPosition(1);
        REQUIRE(home.SwitchPage() == 2);

    }

    SECTION("Switch to middle page") {
        home.AddToPosition(1);
        REQUIRE(home.SwitchPage() == 1);

    }
}