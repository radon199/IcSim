#include "chips/IDT71256SA.h"

using namespace IcSim;

IDT71256SA::IDT71256SA(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"A14", 1},
        {"A12", 2},
        {"A7",  3},
        {"A6",  4},
        {"A5",  5},
        {"A4",  6},
        {"A3",  7},
        {"A2",  8},
        {"A1",  9},
        {"A0",  10},
        {"IO0", 11},
        {"IO1", 12},
        {"IO2", 13},
        {"GND", 14},
        {"IO3", 15},
        {"IO4", 16},
        {"IO5", 17},
        {"IO6", 18},
        {"IO7", 19},
        {"CS",  20},
        {"A10", 21},
        {"OE",  22},
        {"A11", 23},
        {"A9",  24},
        {"A8",  25},
        {"A13", 26},
        {"WE",  27},
        {"VCC", 28},

    };
    set_pins(pins_);

    memory_.resize(32000);
}

void
IDT71256SA::cook(bool& prop)
{
    // If CS or OE are high, output HIGH_Z on the data pins
    if (get_input(20) == 1 || get_input(22) == 1) {
        set_data(11, HIGH_Z, prop);
        set_data(12, HIGH_Z, prop);
        set_data(13, HIGH_Z, prop);
        set_data(15, HIGH_Z, prop);
        set_data(16, HIGH_Z, prop);
        set_data(17, HIGH_Z, prop);
        set_data(18, HIGH_Z, prop);
        set_data(19, HIGH_Z, prop);
        return;
    }

    // build the memory address bitset
    std::bitset<15> address;
    address[0]  = get_input(10);
    address[1]  = get_input(9);
    address[2]  = get_input(8);
    address[3]  = get_input(7);
    address[4]  = get_input(6);
    address[5]  = get_input(5);
    address[6]  = get_input(4);
    address[7]  = get_input(3);
    address[8]  = get_input(25);
    address[9]  = get_input(24);
    address[10] = get_input(21);
    address[11] = get_input(23);
    address[12] = get_input(2);
    address[13] = get_input(26);
    address[14] = get_input(1);
    size_t index = address.to_ullong();

    // If WE is high, read data from memory, else write what is on the data lines into memory
    if (get_input(27) == 1) {
        // Get the value for the memory address
        std::bitset<8> value = memory_[index];

        // Set the output data values from the memory bitset
        set_data(11, value[0], prop);
        set_data(12, value[1], prop);
        set_data(13, value[2], prop);
        set_data(15, value[3], prop);
        set_data(16, value[4], prop);
        set_data(17, value[5], prop);
        set_data(18, value[6], prop);
        set_data(19, value[7], prop);
    } else {
        std::bitset<8> value;
        value[0]  = get_input(11);
        value[1]  = get_input(12);
        value[2]  = get_input(13);
        value[3]  = get_input(15);
        value[4]  = get_input(16);
        value[5]  = get_input(17);
        value[6]  = get_input(18);
        value[7]  = get_input(19);

        // Write the value into the memory address
        memory_[index] = value;
    }
}