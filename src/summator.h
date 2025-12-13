#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/wrapped.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class Summator : public Object {
	GDCLASS(Summator, Object)

    int _count;

protected:
	static void _bind_methods();

public:
	Summator();
	~Summator() override = default;

	void add(int p_value);
    void reset();
    int get_total();
};
