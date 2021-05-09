#ifndef SN74HC163N_H
#define SN74HC163N_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class SN74HC163N : public ChipBase
{
public:
    SN74HC163N(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const SN74HC163N& chip);
protected:
    std::string type_{"SN74HC163N"};
    std::string description_{"4 bit binary counter with synchronous reset and parallel or serial input"};

    unsigned long count_{0};
    bool clocked_{false};
};

inline std::ostream& operator<<(std::ostream& output_stream, const SN74HC163N& chip)
{
    output_stream << std::to_string(chip.output_value("Q3"));
    output_stream << std::to_string(chip.output_value("Q2"));
    output_stream << std::to_string(chip.output_value("Q1"));
    output_stream << std::to_string(chip.output_value("Q0"));
    return output_stream;
}

}

#endif // SN74HC1663_H