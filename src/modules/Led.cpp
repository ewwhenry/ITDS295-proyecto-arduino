#include "Led.hpp"

#include "Config.hpp"
#include <Arduino.h>

void inicializarLed()
{
    pinMode(config::PIN_LED_ROJO, OUTPUT);
    pinMode(config::PIN_LED_VERDE, OUTPUT);
    pinMode(config::PIN_LED_AZUL, OUTPUT);

    apagarLed();
}

void encenderLed()
{
    digitalWrite(config::PIN_LED_ROJO, HIGH);
    digitalWrite(config::PIN_LED_VERDE, HIGH);
    digitalWrite(config::PIN_LED_AZUL, HIGH);
}

void apagarLed()
{
    digitalWrite(config::PIN_LED_ROJO, LOW);
    digitalWrite(config::PIN_LED_VERDE, LOW);
    digitalWrite(config::PIN_LED_AZUL, LOW);
}

void alternarLed(bool &estadoLed)
{
    if (estadoLed)
    {
        apagarLed();
        estadoLed = false;
        return;
    }

    encenderLed();
    estadoLed = true;
}

void establecerColorPorcentaje(int porcentaje)
{
    const RGB color = obtenerColor(porcentaje);

    analogWrite(config::PIN_LED_ROJO, color.r);
    analogWrite(config::PIN_LED_VERDE, color.g);
    analogWrite(config::PIN_LED_AZUL, color.b);
}

RGB obtenerColor(int porcentaje)
{
    porcentaje = constrain(porcentaje, 0, 100);

    RGB color{};

    if (porcentaje <= 50)
    {
        const float transicion = porcentaje / 50.0f;

        color.r = 255;
        color.g = static_cast<uint8_t>(255.0f * transicion + 0.5f);
        color.b = 0;
    }
    else
    {
        const float transicion = (porcentaje - 50) / 50.0f;

        color.r = static_cast<uint8_t>(255.0f * (1.0f - transicion) + 0.5f);
        color.g = 255;
        color.b = 0;
    }

    return color;
}
