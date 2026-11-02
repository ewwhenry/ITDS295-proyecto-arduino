#include <Arduino.h>
#include "AsyncInterval.hpp"
#include "Buzzer.hpp"
#include "Led.hpp"

// Zona de intervalos
AsyncInterval buzzerInterval(2000); // Cada 2000 milisegundos (2 segundos) alternará el estado del buzzer
AsyncInterval ledInterval(1000); // Cada 1000 milisegundos (1 segundo) alternará el estado del LED

// Zona de estados
bool estadoBuzzer = false;
bool estadoLed = false;

void setup()
{
    // "Inicializar" el puerto serie para depuración
    Serial.begin(9600);

    // Inicializar el buzzer
    inicializarBuzzer();

    // Inicializar el LED
    inicializarLed();
}

void loop()
{
    // Comprobar si ha pasado el intervalo de tiempo para alternar el estado del buzzer
    if (buzzerInterval.ready())
    {
        // Alternar el estado del buzzer
        alternarBuzzer(estadoBuzzer);

        // Imprimir el estado actual del buzzer en el puerto serie
        Serial.print("Estado del buzzer: ");
        Serial.println(estadoBuzzer ? "Encendido" : "Apagado");
    }

    // Comprobar si ha pasado el intervalo de tiempo para alternar el estado del LED
    if (ledInterval.ready())
    {
        // Alternar el estado del LED
        alternarLed(estadoLed);

        // Imprimir el estado actual del LED en el puerto serie
        Serial.print("Estado del LED: ");
        Serial.println(estadoLed ? "Encendido" : "Apagado");
    }
}