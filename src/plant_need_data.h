#pragma once

#include "plant_need.h"
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class PlantNeedData : public Resource {
	GDCLASS(PlantNeedData, Resource)

private:
    double base_need_time, need_interaction_window_time;
    String need_message;

protected:
	static void _bind_methods();

public:
    double get_base_need_time() const;
    void set_base_need_time(double p_base_need_time);

    double get_need_interaction_window_time() const;
    void set_need_interaction_window_time(double p_need_interaction_window_time);

    String get_need_message() const;
    void set_need_message(String p_need_message);

	Ref<PlantNeed> create_need() const;
};