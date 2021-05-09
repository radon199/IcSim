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
    const int a = get_input("A");
    const int b = get_input("B");
    const int c = get_input("C");
    const int d = get_input("D");
    const int e = get_input("E");
    const int f = get_input("F");
    const int g = get_input("G");
    const int h = get_input("H");
    if (a && b && c && d && e && f && g && h) {
        set_data("Y", 0, prop);
    } else {
        set_data("Y", 1, prop);
    }
}