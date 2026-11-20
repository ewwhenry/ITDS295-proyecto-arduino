#include <Arduino.h>

#include "AsyncInterval.hpp"
#include "Buzzer.hpp"
#include "Config.hpp"
#include "Distancia.hpp"
#include "HCSR04.hpp"
#include "Led.hpp"
#include "Pantalla.hpp"

namespace
{
    // Temporizadores no bloqueantes
    AsyncInterval medicionInterval(config::INTERVALO_MEDICION_MS);
    AsyncInterval pantallaInterval(config::INTERVALO_PANTALLA_MS);
    AsyncInterval buzzerInterval(config::INTERVALO_BUZZER_INICIAL_MS);
    AsyncInterval readButtonsInterval(config::INTERVALO_LEER_BOTONES_MS);

    // Estado del sistema
    bool estadoBuzzer = false;
    float distanciaCm = 0.0f;
    int porcentajeDistancia = 0;
    NivelDistancia nivelDistancia = NivelDistancia::MuyCerca;
    int status = LOW;  // LOW = apagado, HIGH = encendido
    bool mute = false; //  true = sin sonido, false = con sonido
} // namespace

bool botonPresionado(uint8_t pin)
{
    static bool estadoAnteriorA0 = HIGH;
    static bool estadoAnteriorA1 = HIGH;

    bool estadoActual = digitalRead(pin);

    bool *estadoAnterior = nullptr;

    if (pin == A0)
        estadoAnterior = &estadoAnteriorA0;
    if (pin == A1)
        estadoAnterior = &estadoAnteriorA1;

    if (estadoActual == LOW && *estadoAnterior == HIGH)
    {
        *estadoAnterior = estadoActual;
        return true;
    }

    *estadoAnterior = estadoActual;
    return false;
}

void setup()
{
    Serial.begin(config::BAUDIOS_SERIAL);

    inicializarBuzzer();
    inicializarLed();
    inicializarHCSR04();
    inicializarPantalla();

    pinMode(A0, INPUT_PULLUP); // Botón de encendido/apagado
    pinMode(A1, INPUT_PULLUP); // Botón de silencio

    distanciaCm = medirDistanciaHCSR04();
    if (distanciaCm < 0.0f)
    {
        distanciaCm = config::DISTANCIA_MAXIMA_CM;
    }

    porcentajeDistancia = porcentajeDesdeDistancia(distanciaCm);
    nivelDistancia = nivelDesdePorcentaje(porcentajeDistancia);
    buzzerInterval.setInterval(intervaloBuzzer(nivelDistancia));

    establecerColorPorcentaje(porcentajeDistancia);
    mostrarEstadoSistema(distanciaCm, nivelDistancia);
}

void loop()
{
    if (readButtonsInterval.ready())
    {
        if (botonPresionado(A0))
        {
            status = !status;

            Serial.print("Estado del sistema: ");
            Serial.println(status ? "Encendido" : "Apagado");
        }

        if (botonPresionado(A1))
        {
            mute = !mute;

            Serial.print("Estado del sonido: ");
            Serial.println(mute ? "Silenciado" : "Con sonido");
        }
    }
    if (status == HIGH)
    {
        if (medicionInterval.ready())
        {
            distanciaCm = medirDistanciaHCSR04();
            if (distanciaCm < 0.0f)
            {
                distanciaCm = config::DISTANCIA_MAXIMA_CM;
            }

            porcentajeDistancia = porcentajeDesdeDistancia(distanciaCm);
            nivelDistancia = nivelDesdePorcentaje(porcentajeDistancia);
            buzzerInterval.setInterval(intervaloBuzzer(nivelDistancia));

            establecerColorPorcentaje(porcentajeDistancia);
        }

        if (buzzerInterval.ready())
        {
            if (mute == true)
            {
                desactivarBuzzer();
                estadoBuzzer = false;
            }
            else
            {
                alternarBuzzer(estadoBuzzer, config::FRECUENCIA_BUZZER_HZ);

                Serial.print("Estado del buzzer: ");
                Serial.println(estadoBuzzer ? "Encendido" : "Apagado");
            }
        }

        if (pantallaInterval.ready())
        {
            mostrarEstadoSistema(distanciaCm, nivelDistancia);
        }
    }
    else
    {

        // Si el sistema está apagado, asegurarse de que todo esté apagado
        if (estadoBuzzer)
        {
            alternarBuzzer(estadoBuzzer, config::FRECUENCIA_BUZZER_HZ);
        }
        establecerColorPorcentaje(0); // Apagar LEDs
        apagarPantalla();
    }
}
