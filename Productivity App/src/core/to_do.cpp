//
// Created by asaho on 5/1/2021.
//

#include "core/to_do.h"

namespace productivity {
    ToDo::ToDo(std::string name) {
        name_ = name;
        is_completed_ = false;
    }

    void ToDo::ToggleIsCompleted() {
        is_completed_ = !is_completed_;
    }

    std::string ToDo::GetName() {
        return name_;
    }

    bool ToDo::GetIsCompleted() {
        return is_completed_;
    }

    void ToDo::SetName(std::string name) {
        name_ = name;
    }
}
