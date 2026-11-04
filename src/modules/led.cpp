#include "Led.hpp"
#include <Arduino.h>

// Definimos los pines físicos del arduino donde se conectan los canales del Led RGB
#define LED_Green 4
#define LED_Blue  5
#define LED_Red   6

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
    digitalWrite(LED_Red, LOW);
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_Blue, LOW);

    switch (distancia)
    {
        case 4: // color verde si esta lejos
            digitalWrite(LED_Green, HIGH);
            break;
            
        case 3: // color amarillo si esta moderado
            digitalWrite(LED_Red, HIGH);
            digitalWrite(LED_Green, HIGH);
            break;
            
        case 2: // color azul si esta cerca
            digitalWrite(LED_Blue, HIGH);
            break;
            
        case 1: // color rojo si esta muy cerca
            digitalWrite(LED_Red, HIGH);
            break;
            
        default:
            break;
    }
}