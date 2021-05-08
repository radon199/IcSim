from chip_base import ChipBase
from exceptions import NotConnected

from bitstring import BitArray

class SN74LS161A(ChipBase):
    def __init__(self, name):
        super(SN74LS161A, self).__init__(name)

        self.type = 'SN74LS161A'
        self.discription = "4 bit binary counter with synchronous reset and parallel or serial input"
        self.has_clock_input = True

        self.pins = {
            'MR': 1,
            'CP': 2,
            'P0': 3,
            'P1': 4,
            'P2': 5,
            'P3': 6,
            'CEP': 7,
            'GND': 8,
            'PE': 9,
            'CET': 10,
            'Q3': 11,
            'Q2': 12,
            'Q1': 13,
            'Q0': 14,
            'TC': 15,
            'VCC': 16,
        }

        self.data = {
            'Q0': 0,
            'Q1': 0,
            'Q2': 0,
            'Q3': 0,
            'TC': 0,
        }

        self._count = 0

        self._clocked = False

    def cook(self):
        # The master reset will happen any time MR is low and is not tied to clock
        if self.get_input('MR') == 0:
            self._count = 0
            self.data['Q0'] = 0
            self.data['Q1'] = 0
            self.data['Q2'] = 0
            self.data['Q3'] = 0
            self.data['TC'] = 0
            return

        clk = self.get_input('CP')
        if clk and (not self._clocked):
            # If PE is low, then load the data on the P inputs into the Q outputs and calculate the int count from them
            if self.get_input('PE') == 0:
                self.data['Q0'] = self.get_input('P0')
                self.data['Q1'] = self.get_input('P1')
                self.data['Q2'] = self.get_input('P2')
                self.data['Q3'] = self.get_input('P3')
                self.data['TC'] = 0
                self._count = BitArray(bin="{}{}{}{}".format(self.data['Q3'], self.data['Q2'], self.data['Q1'], self.data['Q0'])).uint
                self._clocked = True
                return
            # Reset the carry flag after a full rise and fall clock
            if self.data.get('TC'):
                self.data['TC'] = 0
            # If CET and CEP are true we count
            cet = self.get_input('CET')
            cep = self.get_input('CEP')
            if cet and cep:
                self._count += 1
                self._clocked = True
        
        if self._clocked and (not clk):
            self._clocked = False

        # Roll over
        if self._count == 16:
            self._count = 0
            self.data['Q0'] = 0
            self.data['Q1'] = 0
            self.data['Q2'] = 0
            self.data['Q3'] = 0
            self.data['TC'] = 1
        
        # Get a lis of binary numbers from the count
        res = [int(i) for i in list('{0:04b}'.format(self._count))]
        self.data['Q0'] = res[3]
        self.data['Q1'] = res[2]
        self.data['Q2'] = res[1]
        self.data['Q3'] = res[0]

    def __str__(self):
        return "{} {} {} {}".format(self.data.get('Q3'),self.data.get('Q2'),self.data.get('Q1'),self.data.get('Q0'))
