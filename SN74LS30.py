from chip_base import ChipBase
from exceptions import (NotConnected, NoConnectedIsConnected)

class SN74LS30(ChipBase):
    def __init__(self, name):
        super(SN74LS30, self).__init__(name)

        self.type = 'SN74LS30'
        self.discription = "8 input NAND gate"

        self.pins = {
            'A': 1,
            'B': 2,
            'C': 3,
            'D': 4,
            'E': 5,
            'F': 6,
            'GND': 7,
            'Y': 8,
            'NC': 9,
            'NC': 10,
            'G': 11,
            'H': 12,
            'NC': 13,
            'VCC': 14,
        }

        self.data = {
            'Y': 1
        }

    def cook(self):
        a = self.get_input('A')
        b = self.get_input('B')
        c = self.get_input('C')
        d = self.get_input('D')
        e = self.get_input('E')
        f = self.get_input('F')
        g = self.get_input('G')
        h = self.get_input('H')

        if a and b and c and d and e and f and g and h:
            self.data['Y'] = 0
        else:
            self.data['Y'] = 1