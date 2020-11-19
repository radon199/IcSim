from exceptions import NotConnected, NoNamedPin, InvalidInput, InvalidOutput, InputFloating, DoesNotSupportBusInput

from collections import defaultdict

# Each output should put out either 0 or 1, but to support a bus type system where
# a input may be connected to the output of many nodes we support a constant value
# HIGH_Z which is equal to -1. If a not doesn't want to put out a values it can return
# this in order to say that it shouldn't be considered. On a bus only one node should
# output a value at any given time, and all others should be HIGH_Z. If this is not
# the case a error will be raised as this is generally a fail condition
HIGH_Z = -1

class ChipConnection:
    """ A struct like class for holding a node and output for connecting
    """
    def __init__(self, node, output):
        self.node = node
        self.output = output

    def __str__(self):
        return 'Connection : node={} output={}'.format(self.node, self.output)


class ChipBase:
    """ Base class that all IC subclass derive from. Handles
    all of the connection logic.
    """
    def __init__(self, name):
        self.name = name
        self.type = None
        self.discription = ""
        self.has_clock_input = False
        self.allow_bus_inputs = False

        self.pins = {}
        self.data = {}
        self.connections = defaultdict(list)

    def cook(self):
        """ Gather the values from all inputs and set them on
        all outputs.
        """
        raise NotImplementedError

    def check_connection(self, input):
        """ Check if a connection to be made is valid.

        Args:
            intput(str): The input on this node to check.
        """
        if not self.allow_bus_inputs and len(self.connections[input]) > 1:
            raise DoesNotSupportBusInput(('Node {} does not support bus input but has'
                ' multiple input connections for pin {}'.format(self.name, input)))

    def connect_node(self, node, output, inputs):
        """ Connect a upstream node output to this nodes input.

        Args:
            node (ChipBase): A node to connect.
            output (str): The output on the downstream node.
            inputs (str|list): The input on this node to connect or a list of inputs
        """

        if isinstance(inputs, list):
            for i in inputs:
                self.check_connection(i)
                self.connections[i].append(ChipConnection(node, output))
        else:
            self.check_connection(inputs)
            self.connections[inputs].append(ChipConnection(node, output))

    def get_input(self, input):
        """ Get the value from an upstream node.

        Args:
            input (int): An input index.
        
        Returns:
            bool: Value
        """
        data = self.connections.get(input)
        if not data:
            raise NotConnected('Input {} on Node {} has no connection'.format(input, self.name))
        for con in data:
            value = con.node.output_value(con.output)
            if not isinstance(value, int):
                raise InvalidOutput('Output {} on Node {} is not an int'.format(input, self.name))
            if value != HIGH_Z:
                return value
        raise InputFloating('Input {} on Node {} has connections but none are returning a vlue'.format(input, self.name))

    def output_value(self, output):
        """ Return the output value of a pin.

        Args:
            output (str): The output pin name
        
        Returns:
            int: The value
        """
        return self.data.get(output)
