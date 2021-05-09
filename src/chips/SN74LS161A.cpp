#include "chips/SN74LS161A.h"

#include <bitset>

using namespace IcSim;

SN74LS161A::SN74LS161A(std::string name) : ChipBase(name)
{
    // Init pins
    PinNameMap pins_ = {
        {"MR",  1},
        {"CP",  2},
        {"P0",  3},
        {"P1",  4},
        {"P2",  5},
        {"P3",  6},
        {"CEP", 7},
        {"GND", 8},
        {"PE",  9},
        {"CET", 10},
        {"Q3",  11},
        {"Q2",  12},
        {"Q1",  13},
        {"Q0",  14},
        {"TC",  15},
        {"VCC", 16},
    };
    set_pins(pins_);

    // Init data
    set_data("Q0", 0);
    set_data("Q1", 0);
    set_data("Q2", 0);
    set_data("Q3", 0);
    set_data("TC", 0);
}

void
SN74LS161A::cook(bool& prop)
{
    // The master reset will happen any time MR is low and is not tied to clock
    if (get_input(1) == 0) {
        count_ = 0;
        set_data(14, 0, prop);
        set_data(13, 0, prop);
        set_data(12, 0, prop);
        set_data(11, 0, prop);
        set_data(15, 0, prop);
        return;
    }
    int clk = get_input(2);
    if (clk && !clocked_) {
        // If PE is low, then load the data_ on the P inputs into the Q outputs and calculate the int count from them
        if (get_input(9) == 0) {
            const int b0 = get_input(3);
            set_data(14, b0, prop);
            const int b1 = get_input(4);
            set_data(13, b1, prop);
            const int b2 = get_input(5);
            set_data(12, b2, prop);
            const int b3 = get_input(6);
            set_data(11, b3, prop);
            set_data(15, 0, prop);
            std::bitset<4> count;
            count[0] = b0;
            count[1] = b1;
            count[2] = b2;
            count[3] = b3;
            count_ = count.to_ullong();
            clocked_ = true;
            return;
        }
        // Reset the carry flag after a full rise and fall clock
        if (output_value(15) == 1) {
            set_data(15, 0, prop);
        }
        // If CET and CEP are true we count
        const int cet = get_input(10);
        const int cep = get_input(7);
        if (cet && cep) {
            count_ += 1;
            clocked_ = true;

            // Roll over
            if (count_ == 16) {
                set_data(15, 1, prop);
                count_ = 0;
            }

            std::bitset<4> count(count_);
            set_data(14, count[0], prop);
            set_data(13, count[1], prop);
            set_data(12, count[2], prop);
            set_data(11, count[3], prop);
        }
    }

    if (clocked_ && !clk) {
        clocked_ = false;
    }
}