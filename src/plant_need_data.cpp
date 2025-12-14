#pragma once

#include "plant_need_data.h"
#include <godot_cpp/core/class_db.hpp>

void PlantNeedData::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_base_need_time"), &PlantNeedData::get_base_need_time);
    ClassDB::bind_method(D_METHOD("set_base_need_time", "base_need_time"), &PlantNeedData::set_base_need_time);

    ClassDB::add_property("PlantNeedData", PropertyInfo(Variant::FLOAT, "base_need_time", PROPERTY_HINT_RANGE, "5,20"), "set_base_need_time", "get_base_need_time");   
}


double PlantNeedData::get_base_need_time() const {
    return base_need_time;
}

void PlantNeedData::set_base_need_time(double p_base_need_time) {
    base_need_time = p_base_need_time;
}