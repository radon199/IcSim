#ifndef SN74LS08_H
#define SN74LS08_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74LS08 : public ChipBase
{
public:
    SN74LS08(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74LS08& chip);
protected:
    std::string type_{"SN74LS08"};
    std::string description_{"Quad 2 input AND gate"};
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74LS08& chip)
{
    output_stream << std::to_string(chip.output_value("Y1"));
    output_stream << std::to_string(chip.output_value("Y2"));
    output_stream << std::to_string(chip.output_value("Y3"));
    output_stream << std::to_string(chip.output_value("Y4"));
    return output_stream;
}

}

#endif // SN74LS08_H