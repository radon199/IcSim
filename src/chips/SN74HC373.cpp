#include "chips/SN74HC373.h"

using namespace IcSim;

SN74HC373::SN74HC373(std::string name) : ChipBase(name)
{
    // Init pins
    PinMap pins_ = {
        {"OE",  1},
        {"Q0",  2},
        {"D0",  3},
        {"D1",  4},
        {"Q1",  5},
        {"Q2",  6},
        {"D2",  7},
        {"D3",  8},
        {"Q3",  9},
        {"GND", 10},
        {"LE",  11},
        {"Q4",  12},
        {"D4",  13},
        {"D5",  14},
        {"Q5",  15},
        {"Q6",  16},
        {"D6",  17},
        {"D7",  18},
        {"Q7",  19},
        {"VCC", 20},
    };
    set_pins(pins_);

    // Init data
    set_data("Q0", 0);
    set_data("Q1", 0);
    set_data("Q2", 0);
    set_data("Q3", 0);
    set_data("Q4", 0);
    set_data("Q5", 0);
    set_data("Q6", 0);
    set_data("Q7", 0);
}

const int
SN74HC373::output_latched_value(const std::string& output) const
{
    PinMap::const_iterator iter = latched_data_.find(output);
    if (iter != latched_data_.cend()) {
        return iter->second;
    }
    throw std::logic_error("Output "+output+" on Node "+name_+" does not contain a value.");
}

void
SN74HC373::cook(bool& prop)
{
    if (get_input("OE")) {
        set_data("Q0", HIGH_Z, prop);
        set_data("Q1", HIGH_Z, prop);
        set_data("Q2", HIGH_Z, prop);
        set_data("Q3", HIGH_Z, prop);
        set_data("Q4", HIGH_Z, prop);
        set_data("Q5", HIGH_Z, prop);
        set_data("Q6", HIGH_Z, prop);
        set_data("Q7", HIGH_Z, prop);
        return;
    }

    if (get_input("LE")) {
        latched_data_["Q0"] = get_input("D0");
        latched_data_["Q1"] = get_input("D1");
        latched_data_["Q2"] = get_input("D2");
        latched_data_["Q3"] = get_input("D3");
        latched_data_["Q4"] = get_input("D4");
        latched_data_["Q5"] = get_input("D5");
        latched_data_["Q6"] = get_input("D6");
        latched_data_["Q7"] = get_input("D7");
    }
    
    set_data("Q0", output_latched_value("Q0"), prop);
    set_data("Q1", output_latched_value("Q1"), prop);
    set_data("Q2", output_latched_value("Q2"), prop);
    set_data("Q3", output_latched_value("Q3"), prop);
    set_data("Q4", output_latched_value("Q4"), prop);
    set_data("Q5", output_latched_value("Q5"), prop);
    set_data("Q6", output_latched_value("Q6"), prop);
    set_data("Q7", output_latched_value("Q7"), prop);
}