#include "Led.hpp"
#include <Arduino.h>

// Definimos el pin físico del Arduino al que conectamos el ánodo del LED
#define LED_PIN 4

void inicializarLed()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // LOW para que comience apagado
}

void encenderLed()
{
    digitalWrite(LED_PIN, HIGH); //HIGH para encender el Led
}

void apagarLed()
{
    digitalWrite(LED_PIN, LOW); //LOW para apagar el Led
}

void alternarLed(bool &estadoLed) //funcion para alternar el estado del led, que recibe un parametro como referencia para saber el estado actual.
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