#include "chip_circuit.h"

#include <exception>
#include <stdexcept>

using namespace IcSim;

ChipCircuit::ChipCircuit() : VCC("VCC", 1), GND("GND", 0)
{
}

void
ChipCircuit::add_chip_instance(ChipBase* instance)
{
    ChipMap::const_iterator iter = chips_.find(instance->get_name());
    if (iter != chips_.end()) {
        throw std::logic_error("Node name "+instance->get_name()+" already exists in the network, cannot create.");
    }

    chips_[instance->get_name()] = instance;
}

void
ChipCircuit::cook_nodes()
{
    for (auto& chip : chips_)
    {
        chip.second->cook();
    }
}

void
ChipCircuit::increment_simulation()
{
    if (subclock_ < subclocks)
    {
        subclock_ += 1;
    } else {
        CLK.cook();
        subclock_ = 0;
    }

    cook_nodes();
}
