#include "chips/SN74LS30.h"

using namespace IcSim;

SN74LS30::SN74LS30(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"A",   1},
        {"B",   2},
        {"C",   3},
        {"D",   4},
        {"E",   5},
        {"F",   6},
        {"GND", 7},
        {"Y",   8},
        {"NC1", 9},
        {"NC2", 10},
        {"G",   11},
        {"H",   12},
        {"NC3", 13},
        {"VCC", 14},
    };
    set_pins(pins_);

    // Init data
    set_data("Y", 1);
}

void
SN74LS30::cook(bool& prop)
{
    const int a = get_input(1);
    const int b = get_input(2);
    const int c = get_input(3);
    const int d = get_input(4);
    const int e = get_input(5);
    const int f = get_input(6);
    const int g = get_input(11);
    const int h = get_input(12);
    if (a && b && c && d && e && f && g && h) {
        set_data(8, 0, prop);
    } else {
        set_data(8, 1, prop);
    }
}