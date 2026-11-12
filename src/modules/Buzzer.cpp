#include "Buzzer.hpp"

#include "Config.hpp"
#include <Arduino.h>

void inicializarBuzzer()
{
    pinMode(config::PIN_BUZZER, OUTPUT);
    desactivarBuzzer();
}

void activarBuzzer(int frecuenciaHz)
{
    tone(config::PIN_BUZZER, frecuenciaHz);
}

void desactivarBuzzer()
{
    noTone(config::PIN_BUZZER);
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

    activarBuzzer(frecuenciaHz);
    estadoBuzzer = true;
}
