#include "AsyncInterval.hpp"
#include <Arduino.h>

AsyncInterval::AsyncInterval(unsigned long ms)
{
    interval = ms;
    previousTime = 0;
}

bool AsyncInterval::ready()
{
    unsigned long currentTime = millis();

    if (currentTime - previousTime >= interval)
    {
        previousTime = currentTime;
        return true;
    }
    return false;
}

void AsyncInterval::setInterval(unsigned long ms)
{
    interval = ms;
}

void AsyncInterval::reset()
{
    previousTime = millis();
}

unsigned long AsyncInterval::getInterval()
{
    return interval;
}