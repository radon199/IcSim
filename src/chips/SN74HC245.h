#ifndef SN74HC245_H
#define SN74HC245_H

#include "chip_base.h"

#include <string>

namespace IcSim
{

class SN74HC245 : public ChipBase
{
public:
    SN74HC245(std::string name);

    bool has_clock_input() const override { return true; };
    bool allow_bus_inputs() const override { return false; };

    void cook(bool& prop) override;

protected:
    std::string type_{"SN74HC245"};
    std::string description_{"Octal Bus Transceiver"};
};


}

#endif // SN74HC245_H