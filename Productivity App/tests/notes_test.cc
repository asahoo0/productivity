#include <catch2/catch.hpp>
#include <visualizer/notes_page.h>

TEST_CASE("Change ToDo") {
    productivity::NotesPage notesPage = productivity::NotesPage(840, 10);
    notesPage.AddNewNote("sleep");

    SECTION("Add char to current note") {
        notesPage.AddToCurrentNote('y');
        REQUIRE(notesPage.GetCurrentNote() == "sleepy");
    }

    SECTION("Backspace char from current note") {
        notesPage.BackSpaceCurrentNote();
        REQUIRE(notesPage.GetCurrentNote() == "slee");
    }

}

TEST_CASE("Edit Word to Find") {
    productivity::NotesPage notesPage = productivity::NotesPage(840, 10);

    SECTION("Add char to current note") {
        notesPage.AddToWordToFind('h');
        REQUIRE(notesPage.GetWordToFind() == "h");
    }

    SECTION("Backspace char from current note") {
        notesPage.AddToWordToFind('h');
        notesPage.BackSpaceWordToFind();
        REQUIRE(notesPage.GetWordToFind() == "");
    }
}

TEST_CASE("Toggle Find") {
    productivity::NotesPage notesPage = productivity::NotesPage(840, 10);

    SECTION("Toggle once") {
        notesPage.ToggleFindMode();
        REQUIRE(notesPage.GetFindMode() == true);
    }

    SECTION("Toggle multiple times") {
        notesPage.ToggleFindMode();
        notesPage.ToggleFindMode();
        REQUIRE(notesPage.GetFindMode() == false);
    }
}