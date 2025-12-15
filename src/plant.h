#pragma once

#include "plant_data.h"
#include "plant_need.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/typed_array.hpp>

using namespace godot;

class Plant : public Node3D
{
    GDCLASS(Plant, Node3D)

    private:
        Ref<PlantData> data;
        TypedArray<PlantNeed> need_instances;

        const NodePath mesh_node_path = NodePath("mesh");
        MeshInstance3D* mesh_instance;

        double curr_growth, curr_growth_percent;
        double curr_health;
        double growth_multiplier = 1.0;

    protected:
	    static void _bind_methods();

    public:
        void _ready() override;
        void _process(double delta) override;

        TypedArray<PlantNeed> get_need_instances() const;
        
        Ref<PlantData> get_plant_data() const;
        void set_plant_data(const Ref<PlantData>& p_plant_data);

        void do_need_timer_expired(Ref<PlantNeed> need) {
            emit_signal("need_timer_expired", need);        
        }

        void modify_growth_multiplier(double p_modifier) {
            growth_multiplier += p_modifier;
            growth_multiplier = std::fmax(growth_multiplier, 0.1);
        }
};
