#ifndef CLOCK_H
#define CLOCK_H

#include "chips/constant_value.h"

#include <string>
#include <iostream>

namespace IcSim
{

class Clock : public ConstantValue
{
public:
    Clock();

    void cook(bool& prop) override;

    void reset();

    int count{0};

    bool should_log() const { return should_log_; }

    friend std::ostream& operator<<(std::ostream& output_stream, const Clock& clock);
protected:
    std::string type_{"Clock"};
    std::string description_{"Outputs a flip flopping clock"};

    int log_count_{0};
    int log_frequency_{20000};

    bool should_log_{false};
};

inline std::ostream& operator<<(std::ostream& output_stream, const Clock& clock)
{
    std::string edge = clock.output_value(1) ? "Rising" : "Falling";
    output_stream << "Clock Edge=" << edge << " Count=" << clock.count;
    return output_stream;
}

}

#endif // CLOCK_H