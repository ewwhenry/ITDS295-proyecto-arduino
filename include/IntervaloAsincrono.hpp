#pragma once

#include <Arduino.h>

class IntervaloAsincrono
{
private:
    unsigned long tiempoAnterior;

public:
    unsigned long intervalo;

public:
    IntervaloAsincrono(unsigned long ms = 1000);

    bool listo();
    void setIntervalo(unsigned long ms);
    void reiniciar();
};