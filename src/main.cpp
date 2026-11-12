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

// Estado del sistema
bool estadoBuzzer = false;
float distanciaCm = 0.0f;
int porcentajeDistancia = 0;
NivelDistancia nivelDistancia = NivelDistancia::MuyCerca;
} // namespace

void setup()
{
    Serial.begin(config::BAUDIOS_SERIAL);

    inicializarBuzzer();
    inicializarLed();
    inicializarHCSR04();
    inicializarPantalla();

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
        alternarBuzzer(estadoBuzzer, config::FRECUENCIA_BUZZER_HZ);

        Serial.print("Estado del buzzer: ");
        Serial.println(estadoBuzzer ? "Encendido" : "Apagado");
    }

    if (pantallaInterval.ready())
    {
        mostrarEstadoSistema(distanciaCm, nivelDistancia);
    }
}
