#pragma once

#include "plant.h"
#include "plant_need.h"
#include "game_manager.h"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/variant/typed_array.hpp>

using namespace godot;

class GameManager;
class Plant;

class UIController : public Control {
    GDCLASS(UIController, Control)

    private:
        NodePath button_container_path;
        Node* button_container = nullptr;

        Ref<PackedScene> need_button_scene;
        TypedArray<Node> need_buttons;

        void on_plant_registered(const Plant* plant);

    protected:
        static void _bind_methods();

    public:
        void _ready() override;

        void set_button_container_path(const NodePath &p_path);
        NodePath get_button_container_path() const;

        void set_need_button_scene(const Ref<PackedScene>& p_scene);
        Ref<PackedScene> get_need_button_scene() const;
};