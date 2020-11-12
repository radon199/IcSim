from constant_value import ConstantValue

class Clock(ConstantValue):
    def __init__(self):
        super(Clock, self).__init__("CLK", 0)

        self.type = 'Clock'
        self.discription = "A special kind of ConstantValue that flip flops every time the clock() function is called."

        self.count = 0

    def clock(self):
        value = (not self.data['A'])
        if value:
            self.count += 1
        self.data['A'] = value

    def __str__(self):
        edge = 'Rising' if self.data['A'] else 'Falling'
        return "Clock : Edge={} Count={}".format(edge, self.count)