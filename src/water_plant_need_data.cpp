#pragma once

#include "plant_need_data.h"
#include "water_plant_need.cpp"
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class WaterPlantNeedData : public PlantNeedData {
    GDCLASS(WaterPlantNeedData, PlantNeedData)

protected:
    static void _bind_methods() {
    }
    
    Ref<PlantNeed> create_need() const override {
        Ref<WaterPlantNeed> need;
        need.instantiate();
        need->initialise(*this);
        return need;
    }
};