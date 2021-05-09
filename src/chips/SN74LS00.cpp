#include "chips/SN74LS00.h"

using namespace IcSim;

SN74LS00::SN74LS00(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"1A",  1},
        {"1B",  2},
        {"1Y",  3},
        {"2A",  4},
        {"2B",  5},
        {"2Y",  6},
        {"GND", 7},
        {"3Y",  8},
        {"3B",  9},
        {"3A",  10},
        {"4Y",  11},
        {"4B",  12},
        {"4A",  13},
        {"VCC", 14},
    };
    set_pins(pins_);

    // Init data
    set_data("1Y", 0);
    set_data("2Y", 0);
    set_data("3Y", 0);
    set_data("4Y", 0);
}

void
SN74LS00::cook(bool& prop)
{
    const int a1 = get_input(1);
    const int b1 = get_input(2);
    if (a1 && b1) {
        set_data(3, 0, prop);
    } else {
        set_data(3, 1, prop);
    }

    const int a2 = get_input(4);
    const int b2 = get_input(5);
    if (a2 && b2) {
        set_data(6, 0, prop);
    } else {
        set_data(6, 1, prop);
    }

    const int a3 = get_input(10);
    const int b3 = get_input(9);
    if (a3 && b3) {
        set_data(8, 0, prop);
    } else {
        set_data(8, 1, prop);
    }

    const int a4 = get_input(13);
    const int b4 = get_input(12);
    if (a4 && b4) {
        set_data(11, 0, prop);
    } else {
        set_data(11, 1, prop);
    }
}