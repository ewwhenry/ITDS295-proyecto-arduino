#include <Arduino.h>
#include "AsyncInterval.hpp"
#include "Buzzer.hpp"

// Zona de intervalos
AsyncInterval buzzerInterval(2000); // Cada 2000 milisegundos (2 segundos) alternará el estado del buzzer

// Zona de estados
bool estadoBuzzer = false;

void setup()
{
    // "Inicializar" el puerto serie para depuración
    Serial.begin(9600);

    // Inicializar el buzzer
    inicializarBuzzer();
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
}