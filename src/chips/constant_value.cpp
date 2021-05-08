#include "chips/constant_value.h"

using namespace IcSim;

ConstantValue::ConstantValue(std::string name, int value) : ChipBase(name)
{
    set_data("A", value);
}

void
ConstantValue::cook(bool& prop)
{
    // do nothing
    prop = false;
}