#pragma once

#include "plant_data.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class Plant : public Node3D
{
    GDCLASS(Plant, Node3D)

    private:
        Ref<PlantData> data;

        const NodePath mesh_node_path = NodePath("mesh");
        MeshInstance3D* mesh_instance;

        double curr_growth, curr_growth_percent;
        double curr_health;

    protected:
	    static void _bind_methods();

    public:
        void _ready() override;
        void _process(double delta) override;
        
        Ref<PlantData> get_plant_data() const;
        void set_plant_data(const Ref<PlantData>& p_plant_data);
};
