#ifndef CONSTANT_VALUE_H
#define CONSTANT_VALUE_H

#include "chip_base.h"

#include <string>
#include <iostream>

namespace IcSim
{

class ConstantValue : public ChipBase
{
public:
    ConstantValue(std::string name, int value);

    void cook(bool& prop) override;

    friend std::ostream& operator<<(std::ostream& output_stream, const ConstantValue& constant_value);
protected:
    std::string type_{"ConstantValue"};
    std::string description_{"Outputs a constant value on it's data pin. Can be used for VCC, GND or logic 0 and 1."};
};

inline std::ostream& operator<<(std::ostream& output_stream, const ConstantValue& constant_value)
{
    output_stream << "ConstantValue " << constant_value.name_ << " Value=" << constant_value.output_value(1);
    return output_stream;
}

}

#endif // CONSTANT_VALUE_H