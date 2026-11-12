/**
 * @file AsyncInterval.hpp
 * @brief Temporizador no bloqueante basado en millis().
 *
 * Permite ejecutar acciones cada cierto intervalo sin detener el hilo
 * principal, evitando el uso de delay().
 */

#pragma once

class AsyncInterval
{
public:
    /**
     * @brief Crea un temporizador con el intervalo indicado.
     *
     * @param ms Intervalo en milisegundos.
     */
    explicit AsyncInterval(unsigned long ms = 1000);

    /**
     * @brief Comprueba si el intervalo ya transcurrió.
     *
     * Si el intervalo transcurrió, reinicia el temporizador y devuelve true.
     *
     * @return true si debe ejecutarse la acción asociada.
     */
    bool ready();

    /**
     * @brief Devuelve el intervalo configurado.
     *
     * @return Intervalo en milisegundos.
     */
    unsigned long getInterval() const;

    /**
     * @brief Cambia el intervalo configurado.
     *
     * @param ms Nuevo intervalo en milisegundos.
     */
    void setInterval(unsigned long ms);

    /**
     * @brief Reinicia el temporizador tomando el tiempo actual como referencia.
     */
    void reset();

private:
    unsigned long previousTime;
    unsigned long interval;
};
