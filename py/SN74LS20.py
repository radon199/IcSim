from chip_base import ChipBase
from exceptions import (NotConnected, NoConnectedIsConnected)

class SN74LS20(ChipBase):
    def __init__(self, name):
        super(SN74LS20, self).__init__(name)

        self.type = 'SN74LS20'
        self.discription = "2 4 input NAND gate"

        self.pins = {
            'A1': 1,
            'B1': 2,
            'NC1': 3,
            'C1': 4,
            'D1': 5,
            'Y1': 6,
            'GND': 7,
            'Y2': 8,
            'A2': 9,
            'B2': 10,
            'NC2': 11,
            'C2': 12,
            'D2': 13,
            'VCC': 14,
        }

        self.data = {
            'Y1': 1,
            'Y2': 1,
        }

    def cook(self):
        a1 = self.get_input('A1')
        b1 = self.get_input('B1')
        c1 = self.get_input('C1')
        d1 = self.get_input('D1')
        if a1 and b1 and c1 and d1:
            self.data['Y1'] = 0
        else:
            self.data['Y1'] = 1

        a2 = self.get_input('A2')
        b2 = self.get_input('B2')
        c2 = self.get_input('C2')
        d2 = self.get_input('D2')
        if a2 and b2 and c2 and d2:
            self.data['Y2'] = 0
        else:
            self.data['Y2'] = 1