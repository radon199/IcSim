from SN74LS00 import SN74LS00
from SN74LS20 import SN74LS20
from SN74LS04 import SN74LS04
from SN74LS30 import SN74LS30
from SN74LS161A import SN74LS161A
from SN74HC163N import SN74HC163N
from SN74HC373 import SN74HC373

from constant_value import ConstantValue
from clock import Clock

class CircuitFactory():
    """ A factory used to control the creation of a circuit and how it is
    run.
    """
    def __init__(self):
        self.subclocks = 2

        self.CLK = Clock()

        self.VCC = ConstantValue('VCC', 1)
        self.GND = ConstantValue('GND', 0)
        self.nodes = {}

        self._subclock = 0

        self._ic_functions = {
            'SN74LS00': SN74LS00,
            'SN74LS04': SN74LS04,
            'SN74LS20': SN74LS20,
            'SN74LS30': SN74LS30,
            'SN74LS161A': SN74LS161A,
            'SN74HC163N': SN74HC163N,
            'SN74HC373': SN74HC373,
        }

    def create_ic(self, name, ic_type):
        """ Create a IC, add it to the list of nodes and return it.

        Args:
            name (str): The IC's name
            ic_type (str): The IC to create

        Returns:
            ChipBase|None: The created IC or None if the ic_type is not createable.
        """
        function = self._ic_functions.get(ic_type, None)
        if not function:
            return None
        node = function(name)
        self.nodes[name] = node
        return node

    def cook_nodes(self):
        """ Cook all nodes in this circuit.
        """
        for name, node in self.nodes.items():
            node.cook()

    def increment_simulation(self):
        """ Simulate the circuit, performing the subclocks and clocks and cooking all nodes
        """
        if self._subclock < self.subclocks:
            self._subclock += 1
        else:
            self.CLK.clock()
            self._subclock = 0

        self.cook_nodes()