#include "chips/SN74HC245.h"

using namespace IcSim;

SN74HC245::SN74HC245(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"DIR", 1},
        {"A1",  2},
        {"A2",  3},
        {"A3",  4},
        {"A4",  5},
        {"A5",  6},
        {"A6",  7},
        {"A7",  8},
        {"A8",  9},
        {"GND", 10},
        {"B8",  11},
        {"B7",  12},
        {"B6",  13},
        {"B5",  14},
        {"B4",  15},
        {"B3",  16},
        {"B2",  17},
        {"B1",  18},
        {"OE",  19},
        {"VCC", 20},
    };
    set_pins(pins_);

    // Init data
    set_data("A1", 0);
    set_data("A2", 0);
    set_data("A3", 0);
    set_data("A4", 0);
    set_data("A5", 0);
    set_data("A6", 0);
    set_data("A7", 0);
    set_data("A8", 0);
    set_data("B1", 0);
    set_data("B2", 0);
    set_data("B3", 0);
    set_data("B4", 0);
    set_data("B5", 0);
    set_data("B6", 0);
    set_data("B7", 0);
    set_data("B8", 0);
}

void
SN74HC245::cook(bool& prop)
{
    if (get_input(19)) {
        set_data(2,  HIGH_Z, prop);
        set_data(3,  HIGH_Z, prop);
        set_data(4,  HIGH_Z, prop);
        set_data(5,  HIGH_Z, prop);
        set_data(6,  HIGH_Z, prop);
        set_data(7,  HIGH_Z, prop);
        set_data(8,  HIGH_Z, prop);
        set_data(9,  HIGH_Z, prop);
        set_data(11, HIGH_Z, prop);
        set_data(12, HIGH_Z, prop);
        set_data(13, HIGH_Z, prop);
        set_data(14, HIGH_Z, prop);
        set_data(15, HIGH_Z, prop);
        set_data(16, HIGH_Z, prop);
        set_data(17, HIGH_Z, prop);
        set_data(18, HIGH_Z, prop);
        return;
    }

    if (get_input(1)) {
        set_data(18, get_input(2), prop);
        set_data(17, get_input(3), prop);
        set_data(16, get_input(4), prop);
        set_data(15, get_input(5), prop);
        set_data(14, get_input(6), prop);
        set_data(13, get_input(7), prop);
        set_data(12, get_input(8), prop);
        set_data(11, get_input(9), prop);
    } else {
        set_data(2, get_input(18), prop);
        set_data(3, get_input(17), prop);
        set_data(4, get_input(16), prop);
        set_data(5, get_input(15), prop);
        set_data(6, get_input(14), prop);
        set_data(7, get_input(13), prop);
        set_data(8, get_input(12), prop);
        set_data(9, get_input(11), prop);
    }
}