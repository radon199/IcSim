#ifndef SN74LS30_H
#define SN74LS30_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74LS30 : public ChipBase
{
public:
    SN74LS30(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74LS30& chip);
protected:
    std::string type_{"SN74LS30"};
    std::string description_{"8 input NAND gate"};
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74LS30& chip)
{
    output_stream << std::to_string(chip.output_value("Y"));
    return output_stream;
}

}

#endif // SN74LS30_H