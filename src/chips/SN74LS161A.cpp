#include "chips/SN74LS161A.h"

#include <bitset>

using namespace IcSim;

SN74LS161A::SN74LS161A(std::string name) : ChipBase(name)
{
    // Init pins
    PinMap pins_ = {
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
    if (get_input("MR") == 0) {
        count_ = 0;
        set_data("Q0", 0, prop);
        set_data("Q1", 0, prop);
        set_data("Q2", 0, prop);
        set_data("Q3", 0, prop);
        set_data("TC", 0, prop);
        return;
    }
    int clk = get_input("CP");
    if (clk && !clocked_) {
        // If PE is low, then load the data_ on the P inputs into the Q outputs and calculate the int count from them
        if (get_input("PE") == 0) {
            const int b0 = get_input("P0");
            set_data("Q0", b0, prop);
            const int b1 = get_input("P1");
            set_data("Q1", b1, prop);
            const int b2 = get_input("P2");
            set_data("Q2", b2, prop);
            const int b3 = get_input("P3");
            set_data("Q3", b3, prop);
            set_data("TC", 0, prop);
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
        if (output_value("TC") == 1) {
            set_data("TC", 0, prop);
        }
        // If CET and CEP are true we count
        const int cet = get_input("CET");
        const int cep = get_input("CEP");
        if (cet && cep) {
            count_ += 1;
            clocked_ = true;

            // Roll over
            if (count_ == 16) {
                set_data("TC", 1, prop);
                count_ = 0;
            }

            std::bitset<4> count(count_);
            set_data("Q0", count[0], prop);
            set_data("Q1", count[1], prop);
            set_data("Q2", count[2], prop);
            set_data("Q3", count[3], prop);
        }
    }

    if (clocked_ && !clk) {
        clocked_ = false;
    }
}