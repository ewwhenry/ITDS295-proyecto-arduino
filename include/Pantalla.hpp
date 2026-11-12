/**
 * @file Pantalla.hpp
 * @brief Interfaz de la pantalla LCD I2C.
 *
 * Permite inicializar el display y mostrar la distancia medida junto con su
 * nivel de cercanía.
 */

#pragma once

#include "Distancia.hpp"

/**
 * @brief Inicializa la pantalla LCD I2C y enciende la retroiluminación.
 */
void inicializarPantalla();

/**
 * @brief Muestra la distancia y el nivel de cercanía en la pantalla.
 *
 * @param distanciaCm Distancia medida en centímetros.
 * @param nivel Nivel de distancia calculado a partir de la medición.
 */
void mostrarEstadoSistema(float distanciaCm, NivelDistancia nivel);
