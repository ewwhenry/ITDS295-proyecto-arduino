#include <Arduino.h>
#include "AsyncInterval.hpp"
#include "Buzzer.hpp"
#include "Led.hpp"

// Zona de intervalos
AsyncInterval buzzerInterval(2000); // Cada 2000 milisegundos alternará el estado del buzzer
AsyncInterval ledInterval(1000); // Cada 1000 milisegundos alternará el estado del LED

// Zona de estados
bool estadoBuzzer = false;
int distancia = 4; // Variable de distancia (4: Lejos, 3: Moderado, 2: Cerca, 1: Muy cerca)

void setup()
{
    // "Inicializar" el puerto serie para depuración
    Serial.begin(9600);

    // Inicializar el buzzer
    inicializarBuzzer();

    // Inicializar el LED
    inicializarLed();

    // Establecer el estado inicial del Led según la distancia
    establecerDistancia(distancia);
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

    // Comprobar si ha pasado el intervalo de tiempo para alternar el estado del Led
    if (ledInterval.ready())
    {
        // Reiniciar la distancia para alternar los colores del Led
        distancia--;
        if (distancia < 1)
        {
            distancia = 4;
        }

        // Establecer el color del Led según la distancia
        establecerDistancia(distancia);

        // Imprimir el nivel de distancia y su color correspondiente
        Serial.print("Distancia: ");
        Serial.print(distancia);
        Serial.print(" -> ");
        if (distancia == 4) Serial.println("Lejos (Verde)");
        else if (distancia == 3) Serial.println("Moderado (Amarillo)");
        else if (distancia == 2) Serial.println("Cerca (Azul)");
        else if (distancia == 1) Serial.println("Muy cerca (Rojo)");
    }
}