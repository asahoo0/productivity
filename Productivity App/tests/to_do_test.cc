#include <catch2/catch.hpp>
#include <visualizer/to_do_page.h>

TEST_CASE("Change Note") {
    productivity::ToDoPage ToDoPage = productivity::ToDoPage(840, 10);
    ToDoPage.AddNewToDo("sleep");

    SECTION("Add char to current note") {
        ToDoPage.AddToCurrentToDo('y');
        REQUIRE(ToDoPage.GetCurrentToDo() == "sleepy");
    }

    SECTION("Backspace char from current note") {
        ToDoPage.BackSpaceToDo();
        REQUIRE(ToDoPage.GetCurrentToDo() == "slee");
    }

}

TEST_CASE("Change Word to Find") {
    productivity::ToDoPage ToDoPage = productivity::ToDoPage(840, 10);

    SECTION("Add char to current note") {
        ToDoPage.AddToWordToFind('h');
        REQUIRE(ToDoPage.GetWordToFind() == "h");
    }

    SECTION("Backspace char from current note") {
        ToDoPage.AddToWordToFind('h');
        ToDoPage.BackSpaceWordToFind();
        REQUIRE(ToDoPage.GetWordToFind() == "");
    }
}

TEST_CASE("Toggle Find Mode") {
    productivity::ToDoPage ToDoPage = productivity::ToDoPage(840, 10);

    SECTION("Toggle once") {
        ToDoPage.ToggleFindMode();
        REQUIRE(ToDoPage.GetFindMode() == true);
    }

    SECTION("Toggle multiple times") {
        ToDoPage.ToggleFindMode();
        ToDoPage.ToggleFindMode();
        REQUIRE(ToDoPage.GetFindMode() == false);
    }
}

TEST_CASE("Toggle Completion Mode") {
    productivity::ToDo ToDo = productivity::ToDo("name");

    SECTION("Toggle once") {
        ToDo.ToggleIsCompleted();
        REQUIRE(ToDo.GetIsCompleted() == true);
    }

    SECTION("Toggle multiple times") {
        ToDo.ToggleIsCompleted();
        ToDo.ToggleIsCompleted();
        REQUIRE(ToDo.GetIsCompleted() == false);
    }
}