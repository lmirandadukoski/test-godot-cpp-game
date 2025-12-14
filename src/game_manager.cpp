#pragma once

#include "game_manager.h"
#include <godot_cpp/core/class_db.hpp>

GameManager* GameManager::instance = nullptr;

void GameManager::_bind_methods() {
    ClassDB::bind_method(
        D_METHOD("set_plant_path", "path"),
        &GameManager::set_plant_path
    );
    ClassDB::bind_method(
        D_METHOD("get_plant_path"),
        &GameManager::get_plant_path
    );

    ADD_PROPERTY(
        PropertyInfo(
            Variant::NODE_PATH,
            "plant",
            PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE,
            "Plant"
        ),
        "set_plant_path",
        "get_plant_path"
    );

    ClassDB::bind_method(
        D_METHOD("set_ui_path", "path"),
        &GameManager::set_ui_path
    );
    ClassDB::bind_method(
        D_METHOD("get_ui_path"),
        &GameManager::get_ui_path
    );

    ADD_PROPERTY(
        PropertyInfo(
            Variant::NODE_PATH,
            "ui",
            PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE,
            "UIController"
        ),
        "set_ui_path",
        "get_ui_path"
    );

    ADD_SIGNAL(MethodInfo(
        "plant_registered",
        PropertyInfo(Variant::OBJECT, "plant", PROPERTY_HINT_RESOURCE_TYPE, "Plant")
    ));
    ADD_SIGNAL(MethodInfo(
        "ui_registered",
        PropertyInfo(Variant::OBJECT, "ui", PROPERTY_HINT_RESOURCE_TYPE, "UIController")
    ));
}

GameManager::GameManager() {
    instance = this;
}

GameManager::~GameManager() {
    if(instance == this)
        instance = nullptr;
}

GameManager* GameManager::get_instance()
{
    return instance;
}

Plant* GameManager::get_plant() const
{
    return plant;
}

void GameManager::set_plant_path(const NodePath &p_path)
{
    plant_path = p_path;
}

NodePath GameManager::get_plant_path() const
{
    return plant_path;
}

UIController* GameManager::get_ui() const
{
    return ui;
}

void GameManager::set_ui_path(const NodePath &p_path)
{
    ui_path = p_path;    
}

NodePath GameManager::get_ui_path() const
{
    return ui_path;    
}

void GameManager::_ready()
{
    if (!plant_path.is_empty()) {
        Node *node = get_node_or_null(plant_path);
        plant = Object::cast_to<Plant>(node);

        if(plant != nullptr) {
            do_plant_registered(plant);
        }
    }

    if (!ui_path.is_empty()) {
        Node *node = get_node_or_null(ui_path);
        ui = Object::cast_to<UIController>(node);

        if(ui != nullptr) {
            do_ui_registered(ui);
        }
    }
}