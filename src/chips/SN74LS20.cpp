#include "chips/SN74LS20.h"

using namespace IcSim;

SN74LS20::SN74LS20(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"A1",  1},
        {"B1",  2},
        {"NC1", 3},
        {"C1",  4},
        {"D1",  5},
        {"Y1",  6},
        {"GND", 7},
        {"Y2",  8},
        {"A2",  9},
        {"B2",  10},
        {"NC2", 11},
        {"C2",  12},
        {"D2",  13},
        {"VCC", 14},
    };
    set_pins(pins_);

    // Init data
    set_data("Y1", 1);
    set_data("Y2", 1);
}

void
SN74LS20::cook(bool& prop)
{
    const int a1 = get_input(1);
    const int b1 = get_input(2);
    const int c1 = get_input(4);
    const int d1 = get_input(5);
    if (a1 && b1 && c1 && d1) {
        set_data(6, 0, prop);
    } else {
        set_data(6, 1, prop);
    }

    const int a2 = get_input(9);
    const int b2 = get_input(10);
    const int c2 = get_input(12);
    const int d2 = get_input(13);
    if (a2 && b2 && c2 && d2) {
        set_data(8, 0, prop);
    } else {
        set_data(8, 1, prop);
    }
}