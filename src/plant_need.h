#pragma once

#include "plant_need_data.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <cmath>

using namespace godot;

class PlantNeedData;

class PlantNeed : public RefCounted {
	GDCLASS(PlantNeed, RefCounted)

private:
	double base_need_time, need_timer;

protected:
	static void _bind_methods();
	virtual void need_timer_expired() = 0;

public:
	void initialise(const PlantNeedData& p_data);
	void update(double delta);
};