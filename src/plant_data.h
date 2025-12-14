#pragma once

#include "plant_need_data.h"

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/typed_array.hpp>

using namespace godot;

class PlantData : public Resource {
	GDCLASS(PlantData, Resource)

private:
    double health, growth_time;
    Ref<Mesh> small_mesh, medium_mesh, large_mesh;
    TypedArray<PlantNeedData> needs;

protected:
	static void _bind_methods();

public:
	PlantData() = default;
	~PlantData() override = default;

    Ref<Mesh> get_small_mesh() const;
    void set_small_mesh(const Ref<Mesh>& p_mesh);
    Ref<Mesh> get_medium_mesh() const;
    void set_medium_mesh(const Ref<Mesh>& p_mesh);
    Ref<Mesh> get_large_mesh() const;
    void set_large_mesh(const Ref<Mesh>& p_mesh);

    double get_health() const;
    void set_health(double p_health);
    double get_growth_time() const;
    void set_growth_time(double p_growth_speed);

    TypedArray<PlantNeedData> get_needs() const;
    void set_needs(const TypedArray<PlantNeedData>& p_needs);

    Ref<Mesh> get_mesh_for_current_growth(double p_current_growth);

	void print_data();
};