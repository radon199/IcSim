#ifndef SN74LS20_H
#define SN74LS20_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74LS20 : public ChipBase
{
public:
    SN74LS20(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74LS20& chip);
protected:
    std::string type_{"SN74LS20"};
    std::string description_{"2 4 input NAND gate"};
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74LS20& chip)
{
    output_stream << std::to_string(chip.output_value("Y1"));
    output_stream << std::to_string(chip.output_value("Y2"));
    return output_stream;
}

}

#endif // SN74LS20_H