/**
 * @file Config.hpp
 * @brief Configuración centralizada de pines, tiempos y umbrales del proyecto.
 *
 * Todos los valores que antes estaban repartidos como números mágicos en los
 * módulos se declaran aquí para facilitar su ajuste y documentación.
 */

#pragma once

#include <Arduino.h>

namespace config
{
// Pines del Arduino UNO
constexpr uint8_t PIN_LED_ROJO = 9;
constexpr uint8_t PIN_LED_VERDE = 5;
constexpr uint8_t PIN_LED_AZUL = 6;
constexpr uint8_t PIN_BUZZER = 2;
constexpr uint8_t PIN_TRIGGER = 7;
constexpr uint8_t PIN_ECHO = 8;

// Pantalla LCD I2C
constexpr uint8_t LCD_DIRECCION = 0x27;
constexpr uint8_t LCD_COLUMNAS = 16;
constexpr uint8_t LCD_FILAS = 2;

// Comunicación serie
constexpr unsigned long BAUDIOS_SERIAL = 9600;

// Intervalos de ejecución
constexpr unsigned long INTERVALO_MEDICION_MS = 60;
constexpr unsigned long INTERVALO_PANTALLA_MS = 250;
constexpr unsigned long INTERVALO_BUZZER_INICIAL_MS = 1000;
constexpr unsigned long INTERVALO_BUZZER_LEJOS_MS = 750;
constexpr unsigned long INTERVALO_BUZZER_MODERADO_MS = 500;
constexpr unsigned long INTERVALO_BUZZER_CERCA_MS = 250;
constexpr unsigned long INTERVALO_BUZZER_MUY_CERCA_MS = 50;

// Frecuencia del buzzer
constexpr int FRECUENCIA_BUZZER_HZ = 1000;

// Sensor HC-SR04
constexpr float DISTANCIA_MAXIMA_CM = 400.0f;
constexpr float VELOCIDAD_SONIDO_CM_US = 0.0343f;
constexpr unsigned long TIMEOUT_ECO_US = 30000;

// Umbrales de distancia expresados en porcentaje (0-100)
constexpr int UMBRAL_LEJOS_PORCENTAJE = 75;
constexpr int UMBRAL_MODERADO_PORCENTAJE = 50;
constexpr int UMBRAL_CERCA_PORCENTAJE = 25;
} // namespace config
