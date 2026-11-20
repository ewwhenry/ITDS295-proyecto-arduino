#include "Buzzer.hpp"

#include "Config.hpp"
#include <Arduino.h>

void inicializarBuzzer()
{
    pinMode(config::PIN_BUZZER, OUTPUT);
    desactivarBuzzer();
}

void activarBuzzer()
{
    digitalWrite(config::PIN_BUZZER, HIGH);
}

void desactivarBuzzer()
{
    digitalWrite(config::PIN_BUZZER, LOW);
}

void alternarBuzzer(bool &estadoBuzzer, int frecuenciaHz)
{
    if (estadoBuzzer)
    {
        desactivarBuzzer();
        estadoBuzzer = false;
        return;
    }

    activarBuzzer();
    estadoBuzzer = true;
}
