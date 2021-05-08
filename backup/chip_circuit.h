#ifndef CHIP_CIRCUIT_H
#define CHIP_CIRCUIT_H

#include "chip_base.h"
#include "chips/constant_value.h"
#include "chips/clock.h"

#include <string>
#include <map>

namespace IcSim
{

typedef std::map<std::string, ChipBase*> ChipMap;

class ChipCircuit
{
public:
    ChipCircuit();

    // Built in chips
    Clock CLK;
    ConstantValue VCC;
    ConstantValue GND;

    void add_chip_instance(ChipBase* instance);

    void cook_nodes();

    void increment_simulation();

    int get_subclock() { return subclock_; }

protected:
    ChipMap chips_;

    int subclocks{2};

    int subclock_{0};
};


}

#endif // CHIP_CIRCUIT_H