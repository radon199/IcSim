#include "chips/SN74LS04.h"

#include <bitset>

using namespace IcSim;

SN74LS04::SN74LS04(std::string name) : ChipBase(name)
{
    // Init pins
    PinMap pins_ = {
        {"1A",  1},
        {"1Y",  2},
        {"2A",  3},
        {"2Y",  4},
        {"3A",  5},
        {"3Y",  6},
        {"GND", 7},
        {"4Y",  8},
        {"4A",  9},
        {"5Y",  10},
        {"5A",  11},
        {"6Y",  12},
        {"6A",  13},
        {"VCC", 14},
    };
    set_pins(pins_);

    // Init data
    set_data("1Y", 0);
    set_data("2Y", 0);
    set_data("3Y", 0);
    set_data("4Y", 0);
    set_data("5Y", 0);
    set_data("6Y", 0);
}

void
SN74LS04::_invert_input(const std::string& input, bool& prop)
{
    set_data(input+"Y", 1-get_input(input+"A"), prop);
}

void
SN74LS04::cook(bool& prop)
{
    _invert_input("1", prop);
    _invert_input("2", prop);
    _invert_input("3", prop);
    _invert_input("4", prop);
    _invert_input("5", prop);
    _invert_input("6", prop);
}