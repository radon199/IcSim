#ifndef IDT71256SA_H
#define IDT71256SA_H

#include "chip_base.h"

#include <bitset>
#include <vector>
#include <string>
#include <iostream>

namespace IcSim
{

class IDT71256SA : public ChipBase
{
public:
    IDT71256SA(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;
protected:
    std::string type_{"IDT71256SA"};
    std::string description_{"256K (32K x 8-Bit) CMOS Static Ram"};

    std::vector<std::bitset<8>> memory_;
};


}

#endif // IDT71256SA_H