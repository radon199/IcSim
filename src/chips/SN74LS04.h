#ifndef SN74LS04_H
#define SN74LS04_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74LS04 : public ChipBase
{
public:
    SN74LS04(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74LS04& chip);
protected:
    std::string type_{"SN74LS04"};
    std::string description_{"Quad 1 input hex inverters"};

    void _invert_input(const int& output, const int& input, bool& prop);
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74LS04& chip)
{
    output_stream << std::to_string(chip.output_value("1Y"));
    output_stream << std::to_string(chip.output_value("2Y"));
    output_stream << std::to_string(chip.output_value("3Y"));
    output_stream << std::to_string(chip.output_value("4Y"));
    output_stream << std::to_string(chip.output_value("5Y"));
    output_stream << std::to_string(chip.output_value("6Y"));
    return output_stream;
}

}

#endif // SN74LS04_H