/**
 * @file Distancia.hpp
 * @brief Conversión y clasificación de distancias medidas por el sensor.
 *
 * Centraliza la lógica que traduce centímetros a porcentaje, clasifica el
 * nivel de cercanía y determina el intervalo de sonido del buzzer.
 */

#pragma once

/**
 * @brief Niveles de cercanía usados por la interfaz del sistema.
 */
enum class NivelDistancia
{
    MuyCerca,
    Cerca,
    Moderado,
    Lejos
};

/**
 * @brief Convierte una distancia en centímetros a un porcentaje de 0 a 100.
 *
 * Una lectura negativa se interpreta como una medición inválida (sin eco) y se
 * trata como un obstáculo lejano.
 *
 * @param distanciaCm Distancia medida en centímetros.
 * @return Porcentaje de distancia saturado al rango 0-100.
 */
int porcentajeDesdeDistancia(float distanciaCm);

/**
 * @brief Clasifica un porcentaje de distancia en un nivel de cercanía.
 *
 * @param porcentaje Distancia normalizada de 0 a 100.
 * @return Nivel de distancia correspondiente.
 */
NivelDistancia nivelDesdePorcentaje(int porcentaje);

/**
 * @brief Devuelve el nombre legible de un nivel de distancia.
 *
 * @param nivel Nivel de distancia.
 * @return Cadena de texto estática con el nombre del nivel.
 */
const char *nombreNivel(NivelDistancia nivel);

/**
 * @brief Obtiene el intervalo de alternancia del buzzer para un nivel.
 *
 * @param nivel Nivel de distancia.
 * @return Intervalo en milisegundos.
 */
unsigned long intervaloBuzzer(NivelDistancia nivel);
