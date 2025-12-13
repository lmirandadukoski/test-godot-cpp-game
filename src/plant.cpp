#include "plant.h"

#include <cmath>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void Plant::_bind_methods()
{
// binding plant data
    ClassDB::bind_method(D_METHOD("get_plant_data"), &Plant::get_plant_data);
    ClassDB::bind_method(D_METHOD("set_plant_data", "data"), &Plant::set_plant_data);

    ClassDB::add_property(
        "Plant", 
        PropertyInfo(
            Variant::OBJECT, 
            "data", 
            PROPERTY_HINT_TYPE_STRING, 
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":PlantData"
        ), 
        "set_plant_data", 
        "get_plant_data"
    );
}

void Plant::_ready()
{
    mesh_instance = get_node<MeshInstance3D>(mesh_node_path);
    curr_health = data->get_health();
    curr_growth_percent = 0.0;
    curr_growth = 0.0;

    mesh_instance->set_mesh(data->get_mesh_for_current_growth(curr_growth_percent));
}

void Plant::_process(double delta)
{
    curr_growth += delta;
    curr_growth = std::fmin(curr_growth, data->get_growth_time());
    curr_growth_percent = curr_growth / data->get_growth_time();
    mesh_instance->set_mesh(data->get_mesh_for_current_growth(curr_growth_percent));   
}

Ref<PlantData> Plant::get_plant_data() const
{
    return data;    
}

void Plant::set_plant_data(const Ref<PlantData>& p_plant_data)
{
    data = p_plant_data;    
}
