#include "Buzzer.hpp"
#include <Arduino.h>

#define BUZZER_PIN 3

void inicializarBuzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void activarBuzzer(int frecuenciaHz)
{
    tone(BUZZER_PIN, frecuenciaHz);
}

void desactivarBuzzer()
{
    noTone(BUZZER_PIN);
}

void alternarBuzzer(bool &estadoBuzzer, int frecuenciaHz)
{
    if (estadoBuzzer)
    {
        desactivarBuzzer();
        estadoBuzzer = false;
    }
    else
    {
        activarBuzzer(frecuenciaHz);
        estadoBuzzer = true;
    }
}