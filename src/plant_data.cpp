#pragma once

#include "plant_data.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void PlantData::_bind_methods()
{
    // binding health
    ClassDB::bind_method(D_METHOD("get_health"), &PlantData::get_health);
    ClassDB::bind_method(D_METHOD("set_health", "health"), &PlantData::set_health);

    ClassDB::add_property("PlantData", PropertyInfo(Variant::FLOAT, "health", PROPERTY_HINT_RANGE, "3,20"), "set_health", "get_health");

    // binding growth speed
    ClassDB::bind_method(D_METHOD("get_growth_time"), &PlantData::get_growth_time);
    ClassDB::bind_method(D_METHOD("set_growth_time", "growth_time"), &PlantData::set_growth_time);

    ClassDB::add_property("PlantData", PropertyInfo(Variant::FLOAT, "growth_time", PROPERTY_HINT_RANGE, "20,500"), "set_growth_time", "get_growth_time");
    
    // binding mesh resources
    ClassDB::bind_method(D_METHOD("get_small_mesh"), &PlantData::get_small_mesh);
    ClassDB::bind_method(D_METHOD("set_small_mesh", "mesh"), &PlantData::set_small_mesh);

    ClassDB::add_property(
        "PlantData", 
        PropertyInfo(
            Variant::OBJECT, 
            "small_mesh", 
            PROPERTY_HINT_TYPE_STRING, 
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":Mesh"
        ), 
        "set_small_mesh", 
        "get_small_mesh"
    );

    ClassDB::bind_method(D_METHOD("get_medium_mesh"), &PlantData::get_medium_mesh);
    ClassDB::bind_method(D_METHOD("set_medium_mesh", "mesh"), &PlantData::set_medium_mesh);

    ClassDB::add_property(
        "PlantData", 
        PropertyInfo(
            Variant::OBJECT, 
            "medium_mesh", 
            PROPERTY_HINT_TYPE_STRING, 
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":Mesh"
        ), 
        "set_medium_mesh", 
        "get_medium_mesh"
    );

    ClassDB::bind_method(D_METHOD("get_large_mesh"), &PlantData::get_large_mesh);
    ClassDB::bind_method(D_METHOD("set_large_mesh", "mesh"), &PlantData::set_large_mesh);

    ClassDB::add_property(
        "PlantData", 
        PropertyInfo(
            Variant::OBJECT, 
            "large_mesh", 
            PROPERTY_HINT_TYPE_STRING, 
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":Mesh"
        ), 
        "set_large_mesh", 
        "get_large_mesh"
    ); 
    
    ClassDB::bind_method(D_METHOD("get_needs"), &PlantData::get_needs);
    ClassDB::bind_method(D_METHOD("set_needs", "needs"), &PlantData::set_needs);
        ClassDB::add_property(
        "PlantData", 
        PropertyInfo(
            Variant::ARRAY, 
            "needs", 
            PROPERTY_HINT_TYPE_STRING, 
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":PlantNeedData"
        ), 
        "set_needs", 
        "get_needs"
    );     
}

Ref<Mesh> PlantData::get_small_mesh() const {
	return small_mesh;
}

void PlantData::set_small_mesh(const Ref<Mesh> &p_mesh) {
    small_mesh = p_mesh;
}

Ref<Mesh> PlantData::get_medium_mesh() const {
	return medium_mesh;
}

void PlantData::set_medium_mesh(const Ref<Mesh> &p_mesh) {
    medium_mesh = p_mesh;
}

Ref<Mesh> PlantData::get_large_mesh() const {
	return large_mesh;
}

void PlantData::set_large_mesh(const Ref<Mesh> &p_mesh) {
    large_mesh = p_mesh;
}

double PlantData::get_health() const {
	return health;
}

void PlantData::set_health(double p_health) {
    health = p_health;
}

double PlantData::get_growth_time() const {
	return growth_time;
}

void PlantData::set_growth_time(double p_growth_time) {
    growth_time = p_growth_time;
}

Ref<Mesh> PlantData::get_mesh_for_current_growth(double p_current_growth)
{
    if(p_current_growth <= 0.45)
        return small_mesh;
    if(p_current_growth <= 1.0)
        return medium_mesh;
    return large_mesh;
}

TypedArray<PlantNeedData> PlantData::get_needs() const {
	return needs;
}

void PlantData::set_needs(const TypedArray<PlantNeedData>& p_needs) {
    needs = p_needs;
}

void PlantData::print_data()
{

}
