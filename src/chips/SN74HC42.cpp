#include "chips/SN74HC42.h"

#include <bitset>

using namespace IcSim;

SN74HC42::SN74HC42(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"0",   1},
        {"1",   2},
        {"2",   3},
        {"3",   4},
        {"4",   5},
        {"5",   6},
        {"6",   7},
        {"GND", 8},
        {"7",   9},
        {"8",   10},
        {"9",   11},
        {"D",   12},
        {"C",   13},
        {"B",   14},
        {"A",   15},
        {"VCC", 16},
    };
    set_pins(pins_);

    // Init data
    set_data("0", 0);
    set_data("1", 0);
    set_data("2", 0);
    set_data("3", 0);
    set_data("4", 0);
    set_data("5", 0);
    set_data("6", 0);
    set_data("7", 0);
    set_data("8", 0);
    set_data("9", 0);
}

void
SN74HC42::cook(bool& prop)
{
    std::bitset<4> binary;
    binary[0] = get_input(15);
    binary[1] = get_input(14);
    binary[2] = get_input(13);
    binary[3] = get_input(12);
    unsigned long decimal = binary.to_ullong();
    if (decimal == 0) {
        set_data(1,  0, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 1) { 
        set_data(1,  1, prop);
        set_data(2,  0, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 2) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  0, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 3) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  0, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 4) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  0, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 5) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  0, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 6) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  0, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 7) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  0, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    } else if (decimal == 8) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 0, prop);
        set_data(11, 1, prop);
    } else if (decimal == 9) { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 0, prop);
    } else { 
        set_data(1,  1, prop);
        set_data(2,  1, prop);
        set_data(3,  1, prop);
        set_data(4,  1, prop);
        set_data(5,  1, prop);
        set_data(6,  1, prop);
        set_data(7,  1, prop);
        set_data(9,  1, prop);
        set_data(10, 1, prop);
        set_data(11, 1, prop);
    }
}