#include "HCSR04.hpp"

#include "Config.hpp"
#include <Arduino.h>

void inicializarHCSR04()
{
    pinMode(config::PIN_TRIGGER, OUTPUT);
    pinMode(config::PIN_ECHO, INPUT);
    digitalWrite(config::PIN_TRIGGER, LOW);
}

float medirDistanciaHCSR04()
{
    digitalWrite(config::PIN_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(config::PIN_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(config::PIN_TRIGGER, LOW);

    const unsigned long duracion = pulseIn(config::PIN_ECHO, HIGH, config::TIMEOUT_ECO_US);

    if (duracion == 0)
    {
        return -1.0f;
    }

    return (duracion * config::VELOCIDAD_SONIDO_CM_US) / 2.0f;
}
