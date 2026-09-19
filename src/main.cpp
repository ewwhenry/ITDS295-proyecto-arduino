#include <Arduino.h>
#include "Buzzer.hpp"
#include "Display.hpp"
#include "HCSR04.hpp"
#include "IntervaloAsincrono.hpp"
#include "RGBLed.hpp"

IntervaloAsincrono lecturaHCSR04(100);
IntervaloAsincrono buzzer(500);
IntervaloAsincrono transicionRGB(5);

unsigned int red = 255;
unsigned int green = 0;
unsigned int blue = 0;

unsigned int objetivoRed = 255;
unsigned int objetivoGreen = 0;
unsigned int objetivoBlue = 0;

bool estadoBuzzer = false;

void actualizarColorRGB(float distancia)
{
    if (distancia <= 3)
    {
        red = 255;
        green = 0;
        blue = 0;
    }
    else if (distancia <= 25)
    {
        float progreso = distancia / 25.0;

        red = 255 * (1.0 - progreso);
        green = 255 * progreso;
        blue = 0;
    }
    else if (distancia <= 50)
    {
        float progreso = (distancia - 25.0) / 25.0;

        red = 0;
        green = 255 * (1.0 - progreso);
        blue = 0;
    }
    else
    {
        red = 0;
        green = 0;
        blue = 255;
    }

    establecerRGB(red, green, blue);
}

void setup()
{
    Serial.begin(9600);
    iniciarBuzzer();
    iniciarDisplay();
    inicializarHCSR04();
    inicializarRGB();
}

void loop()
{
    if (lecturaHCSR04.listo())
    {
        float distancia = leerHCSR04();

        actualizarColorRGB(distancia);

        limpiarDisplay();
        mostrarDisplay(String(distancia));

        if (distancia > 0 && distancia <= 10)
        {
            buzzer.setIntervalo(100);
        }
        else if (distancia > 10 && distancia <= 30)
        {
            buzzer.setIntervalo(150);
        }
        else if (distancia > 30 && distancia <= 50)
        {
            buzzer.setIntervalo(400);
        }
        else
        {
            buzzer.setIntervalo(0);
            apagarBuzzer();
            estadoBuzzer = false;
        }
    }

    if (buzzer.intervalo > 0 && buzzer.listo())
    {
        estadoBuzzer = !estadoBuzzer;

        if (estadoBuzzer)
        {
            encenderBuzzer();
        }
        else
        {
            apagarBuzzer();
        }
    }
}