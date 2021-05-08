#ifndef SN74LS20_H
#define SN74LS20_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74LS00 : public ChipBase
{
public:
    SN74LS00(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74LS00& chip);
protected:
    std::string type_{"SN74LS00"};
    std::string description_{""};
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74LS00& chip)
{
    output_stream << std::to_string(chip.output_value("1Y"));
    output_stream << std::to_string(chip.output_value("2Y"));
    output_stream << std::to_string(chip.output_value("3Y"));
    output_stream << std::to_string(chip.output_value("4Y"));
    return output_stream;
}

}

#endif // SN74LS20_H