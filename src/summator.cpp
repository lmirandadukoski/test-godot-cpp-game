	#include "summator.h"
    #include <godot_cpp/core/class_db.hpp>

    void Summator::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("add", "value"), &Summator::add);
        ClassDB::bind_method(D_METHOD("reset"), &Summator::reset);
        ClassDB::bind_method(D_METHOD("get_total"), &Summator::get_total);
    }
    
    Summator::Summator() {
        _count = 0;
    }

	void Summator::add(int p_value) {
        _count += p_value;
    }

    void Summator::reset() {
        _count = 0;    
    }

    int Summator::get_total() {
        return _count;
    }    
