//
// Created by asaho on 5/3/2021.
//

#include <Windows.h>
#include <iostream>
#include "core/reminder.h"

namespace productivity {

    Reminder::Reminder() {
        name_ = "";
        minutes_ = 0;
        minutes_string_ = "";
    }

    void Reminder::SubtractTime() {
        if (minutes_ <= 0) {
            timer_.stop();
            minutes_ = 0; //account for negative num
        } else if (!timer_.isStopped()) {
            timer_.stop();
            minutes_ -= (timer_.getSeconds() / 60);
            if (minutes_ <= 0) { //timer is not stopped but time ran out
                Beep(400, 500);
                std::cin.get();
            }
            timer_.start();
        }
    }

    void Reminder::AddToName(char letter) {
        name_ += letter;
    }

    void Reminder::AddToMinutes(char letter) {
        minutes_string_ += letter;
        ConvertToMinutes();
    }

    std::string Reminder::GetName() {
        return name_;
    }

    void Reminder::SetName(std::string &name) {
        name_ = name;
    }

    bool Reminder::isNumber() {
        try {
            std::stod(minutes_string_);
        }
        catch (std::invalid_argument invalid_argument) {
            minutes_string_ = ""; //clears the string of the argument
            minutes_ = 0;
            return false;
        }
        return true;

    }

    void Reminder::ConvertToMinutes() {
        if (isNumber()) {
            minutes_ = std::stod(minutes_string_);
        }
    }

    double Reminder::GetMinutes() {
        return minutes_;
    }

    std::string Reminder::GetMinutesString() {
        return minutes_string_;
    }

    void Reminder::SetMinutes(std::string &minutes) {
        minutes_string_ = minutes;
        ConvertToMinutes(); //sets the minutes_ using the string
    }

    void Reminder::StartTimer() {
        timer_.start();
    }
}