#pragma once

#include "plant.h"
#include "ui_controller.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/node_path.hpp>

using namespace godot;

class Plant;
class UIController;

class GameManager : public Node {
    GDCLASS(GameManager, Node)

    private:
        static GameManager* instance;

        NodePath plant_path;
        Plant* plant = nullptr;
        NodePath ui_path;
        UIController* ui = nullptr;

        void do_plant_registered(const Plant* plant) {
            emit_signal("plant_registered", plant);
        }

        void do_ui_registered(const UIController* ui) {
            emit_signal("ui_registered", ui);
        }

    protected:
        static void _bind_methods();

    public:
        GameManager();
        ~GameManager();

        static GameManager* get_instance();

        Plant* get_plant() const;    
        void set_plant_path(const NodePath &p_path);
        NodePath get_plant_path() const;

        UIController* get_ui() const;
        void set_ui_path(const NodePath &p_path);
        NodePath get_ui_path() const;

        void _ready() override;
};