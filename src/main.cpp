#include <Arduino.h>
#include "AsyncInterval.hpp"
#include "Buzzer.hpp"
#include "Led.hpp"
#include "pantalla.hpp"
#include "HCSR04.hpp"

// Zona de intervalos
AsyncInterval buzzerInterval(1000);  // Cada 2000 milisegundos alternará el estado del buzzer
AsyncInterval ledInterval(10);       // Cada 1000 milisegundos alternará el estado del LED
AsyncInterval distanciaInterval(10); // Cada 10 milisegundos medirá la distancia con el sensor HCSR04

// Zona de estados
bool estadoBuzzer = false;
int distancia = 4;     // Variable de distancia (4: Lejos, 3: Moderado, 2: Cerca, 1: Muy cerca)
float rawDistance = 0; // Variable para almacenar la distancia medida por el sensor HCSR04

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

    // Inicializar la pantalla LCD I2C
    inicializarPantalla();

    // Mostrar el estado inicial en la pantalla LCD
    mostrarEstadoSistema(distancia);

    // Inicializar el sensor de distancia HCSR04
    inicializarHCSR04();
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

    if (distanciaInterval.ready())
    {
        rawDistance = medirDistanciaHCSR04();
        distancia = (rawDistance / 400) * 100;

        if (distancia > 75)
        {
            buzzerInterval.setInterval(750);
        }
        else if (distancia > 50)
        {
            buzzerInterval.setInterval(500);
        }
        else if (distancia > 25)
        {
            buzzerInterval.setInterval(250);
        }
        else
        {
            buzzerInterval.setInterval(50);
        }
    }

    // Comprobar si ha pasado el intervalo de tiempo para alternar el estado del Led
    if (ledInterval.ready())
    {
        // Establecer el color del Led según la distancia
        establecerDistancia(distancia);
        // Actualizar la pantalla LCD con el nuevo nivel de distancia
        mostrarEstadoSistema(rawDistance);
    }
}