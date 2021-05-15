#include "chips/SN74LS08.h"

using namespace IcSim;

SN74LS08::SN74LS08(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"A1",  1},
        {"B1",  2},
        {"Y1",  3},
        {"A2",  4},
        {"B2",  5},
        {"Y2",  6},
        {"GND", 7},
        {"Y3",  8},
        {"A3",  9},
        {"B3",  10},
        {"Y4",  11},
        {"A4",  12},
        {"B4",  13},
        {"VCC", 14},
    };
    set_pins(pins_);

    // Init data
    set_data("Y1", 0);
    set_data("Y2", 0);
    set_data("Y3", 0);
    set_data("Y4", 0);
}

void
SN74LS08::cook(bool& prop)
{
    const int a1 = get_input(1);
    const int b1 = get_input(2);
    if (a1 && b1) {
        set_data(3, 1, prop);
    } else {
        set_data(3, 0, prop);
    }

    const int a2 = get_input(4);
    const int b2 = get_input(5);
    if (a2 && b2) {
        set_data(6, 1, prop);
    } else {
        set_data(6, 0, prop);
    }

    const int a3 = get_input(9);
    const int b3 = get_input(10);
    if (a3 && b3) {
        set_data(8, 1, prop);
    } else {
        set_data(8, 0, prop);
    }

    const int a4 = get_input(12);
    const int b4 = get_input(13);
    if (a4 && b4) {
        set_data(11, 1, prop);
    } else {
        set_data(11, 0, prop);
    }
}