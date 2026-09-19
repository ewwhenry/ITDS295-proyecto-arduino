#include "IntervaloAsincrono.hpp"

IntervaloAsincrono::IntervaloAsincrono(unsigned long ms)
{
    intervalo = ms;
    tiempoAnterior = 0;
}

bool IntervaloAsincrono::listo()
{
    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoAnterior >= intervalo)
    {
        tiempoAnterior = tiempoActual;
        return true;
    }
    return false;
}

void IntervaloAsincrono::setIntervalo(unsigned long ms)
{
    intervalo = ms;
}

void IntervaloAsincrono::reiniciar()
{
    tiempoAnterior = millis();
}