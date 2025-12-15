#include "plant_need_data.h"
#include <godot_cpp/core/class_db.hpp>

void PlantNeedData::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_base_need_time"), &PlantNeedData::get_base_need_time);
    ClassDB::bind_method(D_METHOD("set_base_need_time", "base_need_time"), &PlantNeedData::set_base_need_time);

    ClassDB::add_property("PlantNeedData", PropertyInfo(Variant::FLOAT, "base_need_time", PROPERTY_HINT_RANGE, "5,20"), "set_base_need_time", "get_base_need_time");   

    ClassDB::bind_method(D_METHOD("get_need_message"), &PlantNeedData::get_need_message);
    ClassDB::bind_method(D_METHOD("set_need_message", "need_message"), &PlantNeedData::set_need_message);

    ClassDB::add_property("PlantNeedData", PropertyInfo(Variant::STRING, "need_message", PROPERTY_HINT_MULTILINE_TEXT), "set_need_message", "get_need_message");       
    ClassDB::bind_method(D_METHOD("get_need_interaction_window_time"), &PlantNeedData::get_need_interaction_window_time);
    ClassDB::bind_method(D_METHOD("set_need_interaction_window_time", "need_interaction_window_time"), &PlantNeedData::set_need_interaction_window_time);

    ClassDB::add_property("PlantNeedData", PropertyInfo(Variant::FLOAT, "need_interaction_window_time", PROPERTY_HINT_RANGE, "0.75,5"), "set_need_interaction_window_time", "get_need_interaction_window_time");
}


double PlantNeedData::get_base_need_time() const {
    return base_need_time;
}

void PlantNeedData::set_base_need_time(double p_base_need_time) {
    base_need_time = p_base_need_time;
}

double PlantNeedData::get_need_interaction_window_time() const
{
    return need_interaction_window_time;
}

void PlantNeedData::set_need_interaction_window_time(double p_need_interaction_window_time)
{
    need_interaction_window_time = p_need_interaction_window_time;
}

String PlantNeedData::get_need_message() const
{
    return need_message;
}

void PlantNeedData::set_need_message(String p_need_message)
{
    need_message = p_need_message;
}

Ref<PlantNeed> PlantNeedData::create_need() const
{
    Ref<PlantNeed> need;
    need.instantiate();
    return need;    
}