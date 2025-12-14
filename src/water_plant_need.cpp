#pragma once

#include "plant_need.h"
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

class WaterPlantNeed : public PlantNeed {
    GDCLASS(WaterPlantNeed, PlantNeed)

protected:
    static void _bind_methods() {
    }

    void need_timer_expired() override {
        UtilityFunctions::print("plant needs water!");
    }
};