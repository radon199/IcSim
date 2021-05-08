#include "chip_base.h"

#include <exception>
#include <stdexcept>
#include <iostream>
#include <set>

using namespace IcSim;

ChipBase::ChipBase(std::string name)
{
    name_ = name;
}

void
ChipBase::set_pins(const PinMap& pins)
{
    pins_ = pins;
}

void
ChipBase::cook(bool& prop)
{
    // Do Nothing
    prop = false;
}

void
ChipBase::propagate()
{
    ChipSet prop_chips;
    // For each output node trigger a cook
    for (ChipBase* node : output_nodes_) {
        bool prop = false;
        node->cook(prop);
        if (prop) {
            // If that cook caused the node output values to change stage the node for propagation
            prop_chips.insert(node);
        }
    }
    // For all the nodes that should propagate, recurse and propagate them
    for (ChipBase* node : prop_chips) {
        node->propagate();
    }
}

void
ChipBase::LogInputConnections() const
{
    ConnectionMap::const_iterator iter;
    for (iter = input_connections_.cbegin(); iter != input_connections_.cend(); iter++) {
        std::cerr << "InputConnections name: " << get_name();
        std::cerr << " input: " << iter->first;
        for (const ChipConnection& con : iter->second) {
            std::cerr << " output_name: " << con.node->get_name();
            std::cerr << " output_pin: " << con.pin;
        }
        std::cerr << std::endl;
    }
}

void
ChipBase::LogOutputConnections() const
{
    for (ChipBase* node : output_nodes_) {
        std::cerr << "OutputConnections name: " << node->get_name() << " type: " <<  node->get_type() << std::endl;
    }
}

void
ChipBase::check_connection(const std::string& input)
{
    if (!allow_bus_inputs()) {
        ConnectionMap::const_iterator iter = input_connections_.find(input);
        if (iter != input_connections_.cend()) {
            if (iter->second.size() > 1) {
                throw std::logic_error("Node "+name_+" does not support bus but has multiple connections.");
            }
        }
    }
}

void
ChipBase::connect_input(ChipBase* node, const std::string& output, const std::string& input)
{
    // Check the connection is valid
    check_connection(input);
    // Make a holder for the connection
    ChipConnection input_holder;
    input_holder.node = node;
    input_holder.pin = output;
    // Insert into the map, this will make a new entry if required
    input_connections_[input].push_back(input_holder);

    // Connect the input on this node to an output on the upstream node so it can propagate.
    node->connect_output(this);
}

void
ChipBase::connect_input(ChipBase* node, const std::string& output, const InputVector& inputs)
{
    for (const auto input: inputs) {
        connect_input(node, output, input);
    }
}

void
ChipBase::connect_output(ChipBase* node)
{
    output_nodes_.insert(node);
}

const int
ChipBase::get_input(const std::string& input)
{
    ConnectionMap::const_iterator iter = input_connections_.find(input);
    if (iter == input_connections_.cend()) {
        throw std::logic_error("Input "+input+" on Node "+name_+" does not have existing connection.");
    }
    for (const ChipConnection& con : iter->second) {
        const int value = con.node->output_value(con.pin);
        if (value != HIGH_Z) {
            return value;
        }
    }
    throw std::logic_error("Input "+input+" on Node "+name_+" has connections but none are returning a valid value.");
}

const int
ChipBase::output_value(const std::string& output) const
{
    PinMap::const_iterator iter = data_.find(output);
    if (iter != data_.end()) {
        return iter->second;
    }
    throw std::logic_error("Output "+output+" on Node "+name_+" does not contain a value.");
}

void
ChipBase::set_data(std::string pin, const int& value, bool& prop)
{
    PinMap::const_iterator iter = data_.find(pin);
    if (iter == data_.end()) {
        data_[pin] = value;
    } else {
        int previous_value = iter->second;
        data_[pin] = value;
        if (previous_value != value) {
            // If the new value doesn't match the previous we should propagate
            prop = true;
        }
    }
}

void
ChipBase::set_data(std::string pin, const int& value)
{
    bool prop = false;
    set_data(pin, value, prop);
}