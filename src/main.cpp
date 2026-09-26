#include <Arduino.h>
#include "Buzzer.hpp"
#include "AsyncInterval.hpp"

AsyncInterval buzzer(1000);
bool buzzerState = false;

void setup()
{
    Serial.begin(9600);
    inicializarBuzzer();
}

void loop()
{
    if (buzzer.ready())
    {
        if (buzzerState)
        {
            apagarBuzzer();
            buzzerState = false;
        }
        else
        {
            encenderBuzzer();
            buzzerState = true;
        }
    }
}