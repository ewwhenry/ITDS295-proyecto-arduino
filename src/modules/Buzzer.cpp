#include "Buzzer.hpp"
#include <Arduino.h>

const int pinBuzzer = 3;

void inicializarBuzzer()
{
    pinMode(pinBuzzer, OUTPUT);
}

void encenderBuzzer()
{
    tone(pinBuzzer, 1000);
}

void apagarBuzzer()
{
    noTone(pinBuzzer);
}