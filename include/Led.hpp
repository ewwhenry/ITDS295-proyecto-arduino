/**
 * @file Led.hpp
 * @brief Módulo para el control del LED del sistema.
 *
 * Proporciona la interfaz para inicializar el hardware del LED
 * y controlar su estado de encendido, apagado o alternancia.
 */

#pragma once

/**
 * @brief Inicializa el hardware necesario para el LED.
 *
 * Configura el pin del LED como salida digital y establece
 * su estado inicial (apagado). Debe llamarse una sola vez en el setup.
 */
void inicializarLed();

/**
 * @brief Enciende el LED.
 */
void encenderLed();

/**
 * @brief Apaga el LED.
 */
void apagarLed();

/**
 * @brief Alterna el estado del LED entre encendido y apagado.
 *
 * Si el LED está apagado, lo enciende; si está encendido, lo apaga.
 * 
 * @param estadoLed Referencia al estado actual del LED (true si está encendido, false si está apagado).
 */
void alternarLed(bool &estadoLed);

/**
 * @brief Establece el color y estado del LED RGB según el nivel de distancia.
 *
 * @param distancia Nivel de distancia (4: Lejos/Verde, 3: Moderado/Amarillo, 2: Cerca/Azul, 1: Muy cerca/Rojo).
 */
void establecerDistancia(int distancia);