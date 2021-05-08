#ifndef CHIP_BASE_H
#define CHIP_BASE_H

#include <string>
#include <vector>
#include <set>
#include <unordered_map>

#define HIGH_Z -1

namespace IcSim
{

typedef std::unordered_map<std::string, int> PinMap;
typedef std::vector<std::string> InputVector;

class ChipBase;

/// A struct like class for holding a node and pin for connecting
struct ChipConnection
{
    ChipBase* node;
    std::string pin;
};

typedef std::unordered_map<std::string, std::vector<ChipConnection>> ConnectionMap;
typedef std::set<ChipBase*> ChipSet;

/// Base class that all IC subclass derive from. Handles all of the connection logic.
class ChipBase
{
public:
    ChipBase(std::string name);
    ~ChipBase() = default;

    const std::string& get_name() const { return name_; }
    const std::string& get_type() const { return type_; }
    const std::string& get_description() const { return description_; }

    virtual bool has_clock_input() const { return false; }
    virtual bool allow_bus_inputs() const { return false; }

    virtual void cook(bool& prop);
    void propagate();

    void check_connection(const std::string& input);

    void connect_input(ChipBase* node, const std::string& output, const std::string& input);
    void connect_input(ChipBase* node, const std::string& output, const InputVector& inputs);

    void connect_output(ChipBase* node);

    const int get_input(const std::string& input);

    const int output_value(const std::string& output) const;

    void LogInputConnections() const;
    void LogOutputConnections() const;

protected:
    void set_pins(const PinMap& pins);
    void set_data(std::string pin, const int& value, bool& prop);
    void set_data(std::string pin, const int& value);

    std::string name_;
    std::string type_{"ChipBase"};
    std::string description_{"The base for all chips. Should never be used directly."};

    PinMap pins_;
    PinMap data_;

    ConnectionMap input_connections_;
    ChipSet output_nodes_;
};


}

#endif // CHIP_BASE_H