#include "Buzzer.hpp"
#include <Arduino.h>

const int BUZZER_PIN = 8;
unsigned const int BUZZER_FREQUENCY = 800;

void iniciarBuzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void encenderBuzzer()
{
    tone(BUZZER_PIN, BUZZER_FREQUENCY);
}

void apagarBuzzer()
{
    noTone(BUZZER_PIN);
}