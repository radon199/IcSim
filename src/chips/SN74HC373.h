#ifndef SN74HC373_H
#define SN74HC373_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74HC373 : public ChipBase
{
public:
    SN74HC373(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74HC373& chip);
protected:
    std::string type_{"SN74HC373"};
    std::string description_{"8 bit transparent D latch"};

    PinDataVector latched_data_;
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74HC373& chip)
{
    output_stream << std::to_string(chip.output_value("Q0"));
    output_stream << std::to_string(chip.output_value("Q1"));
    output_stream << std::to_string(chip.output_value("Q2"));
    output_stream << std::to_string(chip.output_value("Q3"));
    output_stream << std::to_string(chip.output_value("Q4"));
    output_stream << std::to_string(chip.output_value("Q5"));
    output_stream << std::to_string(chip.output_value("Q6"));
    output_stream << std::to_string(chip.output_value("Q7"));
    return output_stream;
}

}

#endif // SN74HC373_H