/**
 * @file Led.hpp
 * @brief Módulo para el control del LED RGB del sistema.
 *
 * Proporciona la interfaz para inicializar el hardware del LED, controlar su
 * estado de encendido/apagado y establecer un color según la distancia.
 */

#pragma once

#include <stdint.h>

/**
 * @brief Componentes de color de un LED RGB.
 */
struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

/**
 * @brief Inicializa los pines del LED RGB.
 *
 * Configura los tres canales como salida y apaga el LED. Debe llamarse una
 * sola vez en el setup.
 */
void inicializarLed();

/**
 * @brief Enciende todos los canales del LED RGB.
 */
void encenderLed();

/**
 * @brief Apaga todos los canales del LED RGB.
 */
void apagarLed();

/**
 * @brief Alterna el estado del LED entre encendido y apagado.
 *
 * @param estadoLed Referencia al estado actual del LED (true encendido).
 */
void alternarLed(bool &estadoLed);

/**
 * @brief Establece el color del LED a partir de un porcentaje de distancia.
 *
 * El color varía de rojo (0 %) a amarillo (50 %) y de amarillo a verde
 * (100 %).
 *
 * @param porcentaje Distancia normalizada de 0 a 100.
 */
void establecerColorPorcentaje(int porcentaje);

/**
 * @brief Calcula el color correspondiente a un porcentaje de distancia.
 *
 * @param porcentaje Distancia normalizada de 0 a 100.
 * @return Componentes RGB resultantes.
 */
RGB obtenerColor(int porcentaje);
