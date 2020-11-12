from exceptions import NotConnected, NoNamedPin, InvalidInput

class ChipBase:
    """ Base class that all IC subclass derive from. Handles
    all of the connection logic.
    """

    def __init__(self, name):
        self.name = name
        self.type = None
        self.discription = ""
        self.has_clock_input = False

        self.pins = {}
        self.data = {}
        self.connections = {}

    def cook(self):
        """ Gather the values from all inputs and set them on
        all outputs.
        """
        raise NotImplementedError

    def connect_node(self, node, output, inputs):
        """ Connect a upstream node output to this nodes input.

        Args:
            node (ChipBase): A node to connect.
            output (str): The output on the downstream node.
            inputs (str|list): The input on this node to connect or a list of inputs
        """
        if isinstance(inputs, list):
            for i in inputs:
                self.connections[i] = (node, output)
        else:
            self.connections[inputs] = (node, output)

    def get_input(self, input):
        """ Get the value from an upstream node.

        Args:
            input (int): An input index.
        
        Returns:
            bool: Value
        """
        node, output = self.connections.get(input, (None, None))
        if not node:
            raise NotConnected('Node {} and input {} has no connection'.format(self.name, input))
        return node.output_value(output)

    def output_value(self, output):
        """ Return the output value of a pin.

        Args:
            output (str): The output pin name
        
        Returns:
            int: The value
        """
        return self.data.get(output)
