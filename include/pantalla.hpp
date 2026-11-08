#pragma once

void inicializarPantalla();

/**
 * @brief Muestra exclusivamente el nivel de distancia y su estado en el display LCD.
 * 
 * @param distancia Nivel de distancia (4: Lejos, 3: Moderado, 2: Cerca, 1: Muy cerca).
 */
void mostrarEstadoSistema(int distancia);