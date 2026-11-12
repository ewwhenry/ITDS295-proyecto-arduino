#include "AsyncInterval.hpp"

#include <Arduino.h>

AsyncInterval::AsyncInterval(unsigned long ms) : previousTime(0), interval(ms)
{
}

bool AsyncInterval::ready()
{
    const unsigned long currentTime = millis();

    if (currentTime - previousTime >= interval)
    {
        previousTime = currentTime;
        return true;
    }

    return false;
}

unsigned long AsyncInterval::getInterval() const
{
    return interval;
}

void AsyncInterval::setInterval(unsigned long ms)
{
    interval = ms;
}

void AsyncInterval::reset()
{
    previousTime = millis();
}
