#include "ui_controller.h"
#include "plant_need.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <cmath>

void UIController::_bind_methods() {
    ClassDB::bind_method(D_METHOD("on_plant_registered", "plant"), &UIController::on_plant_registered);
    ClassDB::bind_method(D_METHOD("on_need_timer_expired", "plant_need"), &UIController::on_need_timer_expired);

    ClassDB::bind_method(D_METHOD("set_need_message_path", "path"), &UIController::set_need_message_path);
    ClassDB::bind_method(D_METHOD("get_need_message_path"), &UIController::get_need_message_path);
    ADD_PROPERTY(
        PropertyInfo(
            Variant::NODE_PATH,
            "need_message",
            PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE,
            "Label"
        ),
        "set_need_message_path",
        "get_need_message_path"
    );

    ClassDB::bind_method(D_METHOD("set_progress_bar_path", "path"), &UIController::set_progress_bar_path);
    ClassDB::bind_method(D_METHOD("get_progress_bar_path"), &UIController::get_progress_bar_path);
    ADD_PROPERTY(
        PropertyInfo(
            Variant::NODE_PATH,
            "progress_bar",
            PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE,
            "ProgressBar"
        ),
        "set_progress_bar_path",
        "get_progress_bar_path"
    );

    ClassDB::bind_method(D_METHOD("get_need_button_scene"), &UIController::get_need_button_scene);
    ClassDB::bind_method(D_METHOD("set_need_button_scene", "scene"), &UIController::set_need_button_scene);

    ClassDB::add_property(
        "UIController", 
        PropertyInfo(
            Variant::OBJECT, 
            "need_button_scene", 
            PROPERTY_HINT_NODE_PATH_TO_EDITED_NODE, 
            String::num(Variant::OBJECT) + "/" + String::num(PROPERTY_HINT_RESOURCE_TYPE) + ":PackedScene"
        ), 
        "set_need_button_scene", 
        "get_need_button_scene"
    ); 

    ClassDB::bind_method(D_METHOD("on_satisfy_need_button_pressed"),&UIController::on_satisfy_need_button_pressed);
}

void UIController::_ready() {
    if (!need_message_path.is_empty()) {
        auto need_message_node = get_node_or_null(need_message_path);
        if (need_message_node != nullptr) 
            need_message = Object::cast_to<Label>(need_message_node);
    }

    if (!progress_bar_path.is_empty()) {
        auto progress_bar_node = get_node_or_null(progress_bar_path);
        if (progress_bar_node != nullptr) {
            progress_bar = Object::cast_to<ProgressBar>(progress_bar_node);
            progress_bar->set_value(0.0);
        }            
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

void UIController::_process(double delta) {
    if(active_need.is_null())
        return;
    interaction_window_timer += delta;
    auto progress = interaction_window_timer / active_need->get_data()->get_need_interaction_window_time();
    progress_bar->set_value(std::fmin(progress * 100.0, 100.0));
    if(interaction_window_timer < active_need->get_data()->get_need_interaction_window_time())
        return;
    // Interaction window expired
    active_need->do_need_missed();
    clean_up();
}

void UIController::set_need_message_path(const NodePath &p_path)
{
    need_message_path = p_path;    
}

NodePath UIController::get_need_message_path() const
{
    return need_message_path;    
}

void UIController::set_progress_bar_path(const NodePath &p_path)
{
    progress_bar_path = p_path;    
}

NodePath UIController::get_progress_bar_path() const
{
    return progress_bar_path;    
}

void UIController::set_need_button_scene(const Ref<PackedScene>& p_scene)
{
    need_button_scene = p_scene;
}

Ref<PackedScene> UIController::get_need_button_scene() const
{
    return need_button_scene;    
}

void UIController::on_plant_registered(Plant* plant) {
    auto gm = GameManager::get_instance();
    gm->disconnect("plant_registered", Callable(this, "on_plant_registered"));
    plant->connect("need_timer_expired", Callable(this, "on_need_timer_expired"));
}

void UIController::on_need_timer_expired(Ref<PlantNeed> plant_need)
{
    if(plant_need.is_null())
        return;
    active_need = plant_need;

    need_message->set_text(active_need->get_data()->get_need_message());  
    progress_bar->set_value(100.0);
    interaction_window_timer = 0.0;

    auto b = need_button_scene->instantiate();
    satisfy_need_button = Object::cast_to<Button>(b);
    add_child(satisfy_need_button);

    satisfy_need_button->connect("pressed", Callable(this, "on_satisfy_need_button_pressed"));
}

void UIController::on_satisfy_need_button_pressed()
{
    active_need->do_need_satisfied();
    clean_up();    
}

void UIController::clean_up()
{
    need_message->set_text("");  
    progress_bar->set_value(0.0);
    active_need.unref();

    if(satisfy_need_button == nullptr) 
        return;

    remove_child(satisfy_need_button);
    satisfy_need_button->queue_free();
    satisfy_need_button = nullptr;       
}
