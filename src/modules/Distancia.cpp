#include "Distancia.hpp"

#include "Config.hpp"
#include <Arduino.h>

int porcentajeDesdeDistancia(float distanciaCm)
{
    if (distanciaCm < 0.0f)
    {
        return 100;
    }

    const float porcentaje = (distanciaCm / config::DISTANCIA_MAXIMA_CM) * 100.0f;
    return static_cast<int>(constrain(porcentaje, 0.0f, 100.0f));
}

NivelDistancia nivelDesdePorcentaje(int porcentaje)
{
    if (porcentaje >= config::UMBRAL_LEJOS_PORCENTAJE)
    {
        return NivelDistancia::Lejos;
    }

    if (porcentaje >= config::UMBRAL_MODERADO_PORCENTAJE)
    {
        return NivelDistancia::Moderado;
    }

    if (porcentaje >= config::UMBRAL_CERCA_PORCENTAJE)
    {
        return NivelDistancia::Cerca;
    }

    return NivelDistancia::MuyCerca;
}

const char *nombreNivel(NivelDistancia nivel)
{
    switch (nivel)
    {
    case NivelDistancia::Lejos:
        return "Lejos";
    case NivelDistancia::Moderado:
        return "Moderado";
    case NivelDistancia::Cerca:
        return "Cerca";
    case NivelDistancia::MuyCerca:
    default:
        return "Muy cerca";
    }
}

unsigned long intervaloBuzzer(NivelDistancia nivel)
{
    switch (nivel)
    {
    case NivelDistancia::Lejos:
        return config::INTERVALO_BUZZER_LEJOS_MS;
    case NivelDistancia::Moderado:
        return config::INTERVALO_BUZZER_MODERADO_MS;
    case NivelDistancia::Cerca:
        return config::INTERVALO_BUZZER_CERCA_MS;
    case NivelDistancia::MuyCerca:
    default:
        return config::INTERVALO_BUZZER_MUY_CERCA_MS;
    }
}
