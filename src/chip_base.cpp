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

/// Set a map of input pin names to pin numbers
void
ChipBase::set_pins(const PinNameMap& pins)
{
    pins_ = pins;
}

/// Change the internal state of this node, updating it's outputs from it's inputs
void
ChipBase::cook(bool& prop)
{
    // Do Nothing
    prop = false;
}

/// Cook and chips connected to this chip and then propagate to them
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

/// Log all the input connections on this chip that will propagate and cause a cook
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

/// Log all the chips that should be propagated when this chip cooks.
void
ChipBase::LogOutputConnections() const
{
    for (ChipBase* node : output_nodes_) {
        std::cerr << "OutputConnections name: " << node->get_name() << " type: " <<  node->get_type() << std::endl;
    }
}

/// Check that the connection doesn't violate any rules like bus connections
void
ChipBase::check_connection(const int& input)
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

/// Get a pin number for a named input.
int
ChipBase::get_pin_number(const std::string& pin_name) const
{
    PinNameMap::const_iterator iter = pins_.find(pin_name);
    if (iter != pins_.cend()) {
        return iter->second;
    }
    throw std::logic_error("Pin "+pin_name+" on Node "+name_+" not in PinNameMap.");
}

/// Connect the output of another chip to the input of this chip to form a connection
void
ChipBase::connect_input(ChipBase* node, const std::string& output, const std::string& input)
{
    connect_input(node, node->get_pin_number(output), get_pin_number(input));
}

/// Convenience method that takes a string pin name and a vector of inputs to connect.
void
ChipBase::connect_input(ChipBase* node, const std::string& output, const InputStringVector& inputs)
{
    for (const auto input: inputs) {
        connect_input(node, output, input);
    }
}

/// Connect the output of another chip to the input of this chip to form a connection
void
ChipBase::connect_input(ChipBase* node, const int& output, const int& input)
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

/// Convenience method that takes a vector of inputs to connect.
void
ChipBase::connect_input(ChipBase* node, const int& output, const InputVector& inputs)
{
    for (const auto input: inputs) {
        connect_input(node, output, input);
    }
}

/// Add a downsteam chip to this chip's set of output nodes for use when propagating.
void
ChipBase::connect_output(ChipBase* node)
{
    output_nodes_.insert(node);
}

/// Convenience method that takes a string pin name as input
const int
ChipBase::get_input(const std::string& input)
{
    return get_input(get_pin_number(input));
}

/// Get the value for an output on an upstream chip from an input on this chip
const int
ChipBase::get_input(const int& input)
{
    ConnectionMap::const_iterator iter = input_connections_.find(input);
    if (iter == input_connections_.cend()) {
        throw std::logic_error("Input "+std::to_string(input)+" on Node "+name_+" does not have existing connection.");
    }
    for (const ChipConnection& con : iter->second) {
        const int value = con.node->output_value(con.pin);
        if (value != HIGH_Z) {
            return value;
        }
    }
    throw std::logic_error("Input "+std::to_string(input)+" on Node "+name_+" has connections but none are returning a valid value.");
}

/// Convenience method that takes a string pin name as input
const int
ChipBase::output_value(const std::string& output) const
{
    return output_value(get_pin_number(output));
}

/// Output the current value in the PinDataMap for a given pin.
const int
ChipBase::output_value(const int& output) const
{
    PinDataMap::const_iterator iter = data_.find(output);
    if (iter != data_.cend()) {
        return iter->second;
    }
    throw std::logic_error("Output "+std::to_string(output)+" on Node "+name_+" does not contain a value.");
}


/// Convenience method that doesn't take propagate for use when setting inital values
/// in the chip constructor. Takes pin name as input.
void
ChipBase::set_data(std::string pin, const int& value)
{
    bool prop = false;
    set_data(pin, value, prop);
}

/// Convenience method that takes a string pin name as input
void
ChipBase::set_data(std::string pin, const int& value, bool& prop)
{
    set_data(get_pin_number(pin), value, prop);
}


/// Convenience method that doesn't take propagate for use when setting inital values
/// in the chip constructor.
void
ChipBase::set_data(int pin, const int& value)
{
    bool prop = false;
    set_data(pin, value, prop);
}

/// Set the data in the internal PinDataMap. Set the propagate reference if the data
/// is not the same as what was in the map previously.
void
ChipBase::set_data(int pin, const int& value, bool& prop)
{
    PinDataMap::iterator iter = data_.find(pin);
    if (iter == data_.end()) {
        data_[pin] = value;
    } else {
        int previous_value = iter->second;
        if (previous_value != value) {
            data_[pin] = value;
            // If the new value doesn't match the previous we should propagate
            prop = true;
        }
    }
}