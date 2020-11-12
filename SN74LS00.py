from chip_base import ChipBase
from exceptions import NotConnected, InvalidOutput

class SN74LS00(ChipBase):
    def __init__(self, name):
        super(SN74LS00, self).__init__(name)

        self.type = 'SN74LS00'

        self.pins = {
            '1A': 1,
            '1B': 2,
            '1Y': 3,
            '2A': 4,
            '2B': 5,
            '2Y': 6,
            'GND': 7,
            '3Y': 8,
            '3B': 9,
            '3A': 10,
            '4Y': 11,
            '4B': 12,
            '4A': 13,
            'VCC': 14,
        }

        self.data = {
            '1Y': 0,
            '2Y': 0,
            '3Y': 0,
            '4Y': 0,
        }

    def cook(self):
        a1 = self.get_input('1A')
        b1 = self.get_input('1B')

        if a1 and b1:
            self.data['1Y'] = 0
        else:
            self.data['1Y'] = 1

        a2 = self.get_input('2A')
        b2 = self.get_input('2B')

        if a2 and b2:
            self.data['2Y'] = 0
        else:
            self.data['2Y'] = 1

        a3 = self.get_input('3A')
        b3 = self.get_input('3B')

        if a3 and b3:
            self.data['3Y'] = 0
        else:
            self.data['3Y'] = 1

        a4 = self.get_input('4A')
        b4 = self.get_input('4B')

        if a4 and b4:
            self.data['4Y'] = 0
        else:
            self.data['4Y'] = 1
