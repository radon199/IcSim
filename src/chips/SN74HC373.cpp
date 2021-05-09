#include "chips/SN74HC373.h"

using namespace IcSim;

SN74HC373::SN74HC373(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
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
    // resize the internal latched data to the same length as the pin map +1 since pins are indexed from 1
    latched_data_.resize(pins_.size()+1);

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

void
SN74HC373::cook(bool& prop)
{
    if (get_input(1)) {
        set_data(2,  HIGH_Z, prop);
        set_data(5,  HIGH_Z, prop);
        set_data(6,  HIGH_Z, prop);
        set_data(9,  HIGH_Z, prop);
        set_data(12, HIGH_Z, prop);
        set_data(15, HIGH_Z, prop);
        set_data(16, HIGH_Z, prop);
        set_data(19, HIGH_Z, prop);
        return;
    }

    if (get_input(11)) {
        latched_data_[2]  = get_input(3);
        latched_data_[5]  = get_input(4);
        latched_data_[6]  = get_input(7);
        latched_data_[9]  = get_input(8);
        latched_data_[12] = get_input(13);
        latched_data_[15] = get_input(14);
        latched_data_[16] = get_input(17);
        latched_data_[19] = get_input(18);
    }
    
    set_data(2,  latched_data_[2],  prop);
    set_data(5,  latched_data_[5],  prop);
    set_data(6,  latched_data_[6],  prop);
    set_data(9,  latched_data_[9],  prop);
    set_data(12, latched_data_[12], prop);
    set_data(15, latched_data_[15], prop);
    set_data(16, latched_data_[16], prop);
    set_data(19, latched_data_[19], prop);
}