from chip_base import ChipBase
from exceptions import NotConnected, InvalidOutput

class SN74LS04(ChipBase):
    def __init__(self, name):
        super(SN74LS04, self).__init__(name)

        self.type = 'SN74LS04'
        self.discription = "Quad 1 input hex inverters"

        self.pins = {
            '1A': 1,
            '1Y': 2,
            '2A': 3,
            '2Y': 4,
            '3A': 5,
            '3Y': 6,
            'GND': 7,
            '4Y': 8,
            '4A': 9,
            '5Y': 10,
            '5A': 11,
            '6Y': 12,
            '6A': 13,
            'VCC': 14,
        }

        self.data = {
            '1Y': 0,
            '2Y': 0,
            '3Y': 0,
            '4Y': 0,
            '5Y': 0,
            '6Y': 0,
        }

    def _invert_input(self, input_pin):
        self.data['{}Y'.format(input_pin)] = 1-self.get_input('{}A'.format(input_pin))

    def cook(self):
        self._invert_input(1)
        self._invert_input(2)
        self._invert_input(3)
        self._invert_input(4)
        self._invert_input(5)
        self._invert_input(6)
