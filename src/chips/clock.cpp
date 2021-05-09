#include "chips/clock.h"

#include <iostream>

using namespace IcSim;

Clock::Clock() : ConstantValue("CLK", 0)
{
}

void
Clock::cook(bool& prop)
{
    // Increment clock
    int value = !output_value(1);
    if (value) {
        count += 1;
    }
    set_data(1, value, prop);

    // Clock logging
    log_count_ += 1;
    if (log_count_ == log_frequency_) {
        should_log_ = true;
        log_count_ = 0;
    } else {
        should_log_ = false;
    }
}

void
Clock::reset()
{
    count = 0;
    log_count_ = 0;
}
