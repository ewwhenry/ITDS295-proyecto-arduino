/**
 * @file buzzer.h
 * @brief Módulo para el control del zumbador (buzzer) del sistema.
 *
 * Proporciona la interfaz para inicializar el hardware del buzzer
 * y controlar su estado de encendido y apagado.
 */

#pragma once

/**
 * @brief Inicializa el hardware necesario para el buzzer.
 *
 * Configura los pines del microcontrolador como salida y establece
 * el estado inicial (apagado). Debe llamarse una sola vez al inicio
 * del programa antes de utilizar las demás funciones.
 */
void inicializarBuzzer();

/**
 * @brief Activa el buzzer, haciendo que emita sonido.
 *
 * Esta función enciende el buzzer, permitiendo que emita un tono audible.
 *
 * @param frecuenciaHz  La frecuencia del sonido en hercios.
 *                      (1000 Hz por defecto)
 */
void activarBuzzer(int frecuenciaHz = 1000);

/**
 * @brief Desactiva el buzzer, deteniendo cualquier sonido emitido.
 *
 * Esta función apaga el buzzer, deteniendo cualquier tono que esté sonando.
 */
void desactivarBuzzer();

/**
 * @brief Alterna el estado del buzzer entre encendido y apagado.
 *
 * Si el buzzer está apagado, lo enciende; si está encendido, lo apaga.
 * Esta función es útil para crear efectos de sonido intermitentes.
 *
 * @param estadoBuzzer  Referencia al estado del buzzer (true si está encendido, false si está apagado).
 * @param frecuenciaHz  La frecuencia del sonido en hercios cuando se activa.
 *                      (1000 Hz por defecto)
 */
void alternarBuzzer(bool &estadoBuzzer, int frecuenciaHz = 1000);