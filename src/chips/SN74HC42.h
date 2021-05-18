#ifndef SN74HC42_H
#define SN74HC42_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74HC42 : public ChipBase
{
public:
    SN74HC42(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74HC42& chip);
protected:
    std::string type_{"SN74HC42"};
    std::string description_{"4 to 10 line decoder"};
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74HC42& chip)
{
    output_stream << std::to_string(chip.output_value("0"));
    output_stream << std::to_string(chip.output_value("1"));
    output_stream << std::to_string(chip.output_value("2"));
    output_stream << std::to_string(chip.output_value("3"));
    output_stream << std::to_string(chip.output_value("4"));
    output_stream << std::to_string(chip.output_value("5"));
    output_stream << std::to_string(chip.output_value("6"));
    output_stream << std::to_string(chip.output_value("7"));
    output_stream << std::to_string(chip.output_value("8"));
    output_stream << std::to_string(chip.output_value("9"));
    return output_stream;
}

}

#endif // SN74HC42_H
