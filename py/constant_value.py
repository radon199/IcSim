from chip_base import ChipBase
from exceptions import NotConnected

class ConstantValue(ChipBase):
    def __init__(self, name, value):
        super(ConstantValue, self).__init__(name)

        self.type = 'ConstantValue'
        self.discription = "Outputs a constant value on it's data pin. Can be used for VCC, GND or logic 0 and 1."

        self.pins = {
            'A': 1,
        }

        self.data = {
            'A': int(value),
        }
