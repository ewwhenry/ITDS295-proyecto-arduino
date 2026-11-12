/**
 * @file HCSR04.hpp
 * @brief Interfaz del sensor ultrasónico HC-SR04.
 *
 * Permite inicializar el sensor y obtener la distancia medida en centímetros.
 */

#pragma once

/**
 * @brief Inicializa los pines del sensor HC-SR04.
 *
 * Configura el pin de disparo como salida, el pin de eco como entrada y deja
 * el pin de disparo en nivel bajo.
 */
void inicializarHCSR04();

/**
 * @brief Mide la distancia al obstáculo más cercano.
 *
 * Envía un pulso de disparo de 10 microsegundos y mide el tiempo de respuesta
 * del eco. Si no se recibe respuesta dentro del tiempo máximo configurado,
 * devuelve un valor negativo para indicar una lectura inválida.
 *
 * @return Distancia en centímetros, o -1.0f si no hubo eco.
 */
float medirDistanciaHCSR04();
