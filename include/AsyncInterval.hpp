#pragma once

class AsyncInterval
{
private:
    unsigned long previousTime;
    unsigned long interval;

public:
    AsyncInterval(unsigned long ms = 1000);

    bool ready();
    unsigned long getInterval();
    void setInterval(unsigned long ms);
    void reset();
};