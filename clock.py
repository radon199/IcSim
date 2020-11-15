import logging

from constant_value import ConstantValue

log = logging.getLogger('Clock')

class Clock(ConstantValue):
    def __init__(self):
        super(Clock, self).__init__('CLK', 0)

        self.type = 'Clock'
        self.discription = "A special kind of ConstantValue that flip flops every time the clock() function is called."

        self.log_frequency = 10000

        self.count = 0
        self._log_count = 0

    def clock(self):
        value = (not self.data['A'])
        if value:
            self.count += 1
        self.data['A'] = value
        # Log clock counting
        self._log_count += 1
        if self._log_count == self.log_frequency:
            log.debug('Current Count: {}'.format(self.count))
            self._log_count = 0

    def reset(self):
        """ Reset the clock count.
        """
        self.count = 0
        self._log_count = 0

    def __str__(self):
        edge = 'Rising' if self.data['A'] else 'Falling'
        return "Clock : Edge={} Count={}".format(edge, self.count)