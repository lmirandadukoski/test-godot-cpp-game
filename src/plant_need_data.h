#pragma once

#include "plant_need.h"
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class PlantNeed;

class PlantNeedData : public Resource {
	GDCLASS(PlantNeedData, Resource)

private:
    double base_need_time;

protected:
	static void _bind_methods();

public:
    double get_base_need_time() const;
    void set_base_need_time(double p_base_need_time);

	virtual Ref<PlantNeed> create_need() const = 0;
};