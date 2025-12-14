#pragma once

#include "ui_controller.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void UIController::_bind_methods() {
    ClassDB::bind_method(D_METHOD("on_plant_registered", "plant"), &UIController::on_plant_registered);
    ClassDB::bind_method(
        D_METHOD("set_button_container_path", "path"),
        &UIController::set_button_container_path
    );
    ClassDB::bind_method(
        D_METHOD("get_button_container_path"),
        &UIController::get_button_container_path
    );

    ADD_PROPERTY(
        PropertyInfo(
            Variant::NODE_PATH,
            "button_container",
            PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE,
            "Control"
        ),
        "set_button_container_path",
        "get_button_container_path"
    );

    ClassDB::bind_method(D_METHOD("get_need_button_scene"), &UIController::get_need_button_scene);
    ClassDB::bind_method(D_METHOD("set_need_button_scene", "scene"), &UIController::set_need_button_scene);

    ClassDB::add_property(
        "UIController", 
        PropertyInfo(
            Variant::OBJECT, 
            "need_button_scene", 
            PROPERTY_HINT_TYPE_STRING, 
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":PackedScene"
        ), 
        "set_need_button_scene", 
        "get_need_button_scene"
    ); 
}

void UIController::_ready() {
    if (!button_container_path.is_empty()) {
        button_container = get_node_or_null(button_container_path);
    }

    auto gm = GameManager::get_instance();
    if(!gm) {
        UtilityFunctions::print("UIController: GameManager instance not found");
        return;
    }
    auto plant = gm->get_plant();
    if(!plant) {
        gm->connect("plant_registered", Callable(this, "on_plant_registered"));
        return;
    }
}

void UIController::set_button_container_path(const NodePath &p_path)
{
    button_container_path = p_path;    
}

NodePath UIController::get_button_container_path() const
{
    return button_container_path;    
}

void UIController::set_need_button_scene(const Ref<PackedScene>& p_scene)
{
    need_button_scene = p_scene;
}

Ref<PackedScene> UIController::get_need_button_scene() const
{
    return need_button_scene;    
}

void UIController::on_plant_registered(const Plant* plant) {
    auto gm = GameManager::get_instance();
    gm->disconnect("plant_registered", Callable(this, "on_plant_registered"));

    auto pni = plant->get_need_instances();
    for (int i = 0; i < (int)pni.size(); ++i) {
        Ref<PlantNeed> pnd = pni[i];
        Node* button_instance = need_button_scene->instantiate();
        button_container->add_child(button_instance);
        need_buttons.append(button_instance);
    }    
}