#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <cmath>

using namespace godot;

class Plant;
class PlantNeedData;

class PlantNeed : public RefCounted {
	GDCLASS(PlantNeed, RefCounted)

private:
	Plant* plant;
	Ref<PlantNeedData> data;
	double need_timer;

protected:
	static void _bind_methods();

public:
	Ref<PlantNeedData> get_data() const { return data; }

	void initialise(Plant* p_plant, Ref<PlantNeedData> p_data);
	void update(double delta);

	void do_need_satisfied();
	void do_need_missed();
};