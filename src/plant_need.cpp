#include "plant.h"
#include "plant_need.h"
#include "plant_need_data.h"

void PlantNeed::_bind_methods() {
}

void PlantNeed::initialise(Plant* p_plant, Ref<PlantNeedData> p_data) {
	plant = p_plant;
	data = p_data;
	need_timer = 0.0;
}

void PlantNeed::update(double delta) {
	if(need_timer >= data->get_base_need_time())
		return;

	need_timer += delta;
	need_timer = std::fmin(need_timer, data->get_base_need_time());
	if(need_timer >= data->get_base_need_time()) {
		plant->do_need_timer_expired(Ref<PlantNeed>(this));
	}		
}

void PlantNeed::do_need_satisfied()
{
	need_timer = 0.0;	
}

void PlantNeed::do_need_missed()
{
	need_timer = 0.0;
	plant->modify_growth_multiplier(-0.1);
}