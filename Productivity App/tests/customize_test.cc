#include <catch2/catch.hpp>
#include <visualizer/customize_page.h>

TEST_CASE("Add to Position Test") {
   productivity::CustomizePage customize = productivity::CustomizePage(10, 840);
    productivity::Theme theme = productivity::Theme("blue","violet","cool");

    SECTION("Position Cannot be Negative") {
        customize.AddToPosition(-1);
        REQUIRE(customize.GetSelectedTheme().GetName() == "dark");
    }

    SECTION("Position can't be greater than pages list size") {
        customize.AddToPosition(1);
        REQUIRE(customize.GetSelectedTheme().GetName() == "dark");
    }

    customize.AddTheme(theme);

    SECTION("Position Can be Added To") {
        customize.AddToPosition(1);
        REQUIRE(customize.GetSelectedTheme().GetName() == theme.GetName());
    }

    SECTION("Position Can be Subtracted From") {
        customize.AddToPosition(1);
        customize.AddToPosition(-1);
        REQUIRE(customize.GetSelectedTheme().GetName() == "dark");
    }

}