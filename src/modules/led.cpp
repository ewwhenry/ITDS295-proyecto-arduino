#include "Led.hpp"
#include <Arduino.h>

// Definimos los pines físicos del arduino donde se conectan los canales del Led RGB
#define LED_Green 5
#define LED_Blue 6
#define LED_Red 3

void inicializarLed()
{
    pinMode(LED_Red, OUTPUT);
    pinMode(LED_Green, OUTPUT);
    pinMode(LED_Blue, OUTPUT);

    // LOW para que comiencen apagados
    digitalWrite(LED_Red, LOW);
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_Blue, LOW);
}

void encenderLed()
{
    // Enciende todos los pines del Led RGB
    digitalWrite(LED_Red, HIGH);
    digitalWrite(LED_Green, HIGH);
    digitalWrite(LED_Blue, HIGH);
}

void apagarLed()
{
    // Apaga todos los canales del LED RGB
    digitalWrite(LED_Red, LOW);
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_Blue, LOW);
}

void alternarLed(bool &estadoLed) // funcion para alternar el estado del led, que recibe un parametro como referencia para saber el estado actual.
{
    if (estadoLed)
    {
        apagarLed();
        estadoLed = false;
    }
    else
    {
        encenderLed();
        estadoLed = true;
    }
}

void establecerDistancia(int distancia)
{
    // Primero apagamos todos los canales para evitar mezclas de colores
    analogWrite(LED_Red, 0);
    analogWrite(LED_Green, 0);
    analogWrite(LED_Blue, 0);

    RGB color = getColor(distancia);
    analogWrite(LED_Red, color.r);
    analogWrite(LED_Green, color.g);
    analogWrite(LED_Blue, color.b);
}

RGB getColor(float distance)
{
    distance = constrain(distance, 0.0, 100.0);

    RGB color;

    // Transición rojo -> amarillo
    if (distance <= 50.0)
    {
        float t = distance / 50.0;

        color.r = 255;
        color.g = 255 * t;
        color.b = 0;
    }
    // Transición amarillo -> verde
    else
    {
        float t = (distance - 50.0) / 50.0;

        color.r = 255 * (1.0 - t);
        color.g = 255;
        color.b = 0;
    }

    return color;
}