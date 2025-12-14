#pragma once

#include "plant_need.h"

void PlantNeed::_bind_methods() {
}

void PlantNeed::initialise(const PlantNeedData& p_data) {
	base_need_time = p_data.get_base_need_time();
	need_timer = 0.0;
}

void PlantNeed::update(double delta) {
	need_timer += delta;
	need_timer = std::fmin(need_timer, base_need_time);
	if(need_timer >= base_need_time)
		need_timer_expired();
}