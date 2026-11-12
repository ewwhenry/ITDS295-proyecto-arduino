/**
 * @file Buzzer.hpp
 * @brief Módulo para el control del zumbador (buzzer) del sistema.
 *
 * Proporciona la interfaz para inicializar el hardware del buzzer y controlar
 * su estado de encendido y apagado.
 */

#pragma once

/**
 * @brief Inicializa el pin del buzzer y lo deja apagado.
 *
 * Debe llamarse una sola vez al inicio del programa antes de utilizar las
 * demás funciones.
 */
void inicializarBuzzer();

/**
 * @brief Activa el buzzer con la frecuencia indicada.
 *
 * @param frecuenciaHz Frecuencia del sonido en hercios.
 */
void activarBuzzer(int frecuenciaHz);

/**
 * @brief Desactiva el buzzer, deteniendo cualquier sonido emitido.
 */
void desactivarBuzzer();

/**
 * @brief Alterna el estado del buzzer entre encendido y apagado.
 *
 * @param estadoBuzzer Referencia al estado actual del buzzer (true encendido).
 * @param frecuenciaHz Frecuencia del sonido cuando se activa.
 */
void alternarBuzzer(bool &estadoBuzzer, int frecuenciaHz);
