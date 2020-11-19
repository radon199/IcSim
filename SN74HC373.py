from chip_base import ChipBase, HIGH_Z
from exceptions import NotConnected, InvalidOutput

class SN74HC373(ChipBase):
    def __init__(self, name):
        super(SN74HC373, self).__init__(name)

        self.type = 'SN74HC373'
        self.discription = "8 bit transparent D latch"

        self.pins = {
            'OE': 1,
            'Q0': 2,
            'D0': 3,
            'D1': 4,
            'Q1': 5,
            'Q2': 6,
            'D2': 7,
            'D3': 8,
            'Q3': 9,
            'GND': 10,
            'LE': 11,
            'Q4': 12,
            'D4': 13,
            'D5': 14,
            'Q5': 15,
            'Q6': 16,
            'D6': 17,
            'D7': 18,
            'Q7': 19,
            'VCC': 20,
        }

        self.data = {
            'Q0': 0,
            'Q1': 0,
            'Q2': 0,
            'Q3': 0,
            'Q4': 0,
            'Q5': 0,
            'Q6': 0,
            'Q7': 0,
        }

        self._latched_data = {
            'Q0': 0,
            'Q1': 0,
            'Q2': 0,
            'Q3': 0,
            'Q4': 0,
            'Q5': 0,
            'Q6': 0,
            'Q7': 0,
        }

    def cook(self):
        # If output enable is high output HIGH_Z on the connections
        if self.get_input('OE') == 1:
            self.data['Q0'] = HIGH_Z
            self.data['Q1'] = HIGH_Z
            self.data['Q2'] = HIGH_Z
            self.data['Q3'] = HIGH_Z
            self.data['Q4'] = HIGH_Z
            self.data['Q5'] = HIGH_Z
            self.data['Q6'] = HIGH_Z
            self.data['Q7'] = HIGH_Z
            return

        if self.get_input('LE') == 1:
            self._latched_data['Q0'] = self.get_input('D0')
            self._latched_data['Q1'] = self.get_input('D1')
            self._latched_data['Q2'] = self.get_input('D2')
            self._latched_data['Q3'] = self.get_input('D3')
            self._latched_data['Q4'] = self.get_input('D4')
            self._latched_data['Q5'] = self.get_input('D5')
            self._latched_data['Q6'] = self.get_input('D6')
            self._latched_data['Q7'] = self.get_input('D7')

        self.data['Q0'] = self._latched_data['Q0']
        self.data['Q1'] = self._latched_data['Q1']
        self.data['Q2'] = self._latched_data['Q2']
        self.data['Q3'] = self._latched_data['Q3']
        self.data['Q4'] = self._latched_data['Q4']
        self.data['Q5'] = self._latched_data['Q5']
        self.data['Q6'] = self._latched_data['Q6']
        self.data['Q7'] = self._latched_data['Q7']
