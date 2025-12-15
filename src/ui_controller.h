#pragma once

#include "game_manager.h"
#include "plant.h"

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/progress_bar.hpp>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>

using namespace godot;

class PlantNeed;

class UIController : public Control {
    GDCLASS(UIController, Control)

    private:
        NodePath need_message_path;
        Label* need_message;

        NodePath progress_bar_path;
        ProgressBar* progress_bar;

        Ref<PackedScene> need_button_scene;
        Button* satisfy_need_button;
        Ref<RandomNumberGenerator> rng;
        Vector2 get_random_screen_position(Vector2 margin);

        Ref<PlantNeed> active_need = nullptr;
        double interaction_window_timer;

        void on_plant_registered(Plant* plant);
        void on_need_timer_expired(Ref<PlantNeed> plant_need);
        void on_satisfy_need_button_pressed();
        void clean_up();

    protected:
        static void _bind_methods();

    public:
        void _ready() override;
        void _process(double delta) override;

        void set_need_message_path(const NodePath &p_path);
        NodePath get_need_message_path() const;

        void set_progress_bar_path(const NodePath &p_path);
        NodePath get_progress_bar_path() const;

        void set_need_button_scene(const Ref<PackedScene>& p_scene);
        Ref<PackedScene> get_need_button_scene() const;
};