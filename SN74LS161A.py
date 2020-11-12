from chip_base import ChipBase
from exceptions import NotConnected

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
            # Reset the carry flag after a full rise and fall clock
            if self.data.get('TC'):
                self.data['TC'] = 0
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
