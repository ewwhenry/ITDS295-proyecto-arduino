# AsyncInterval

Archivo: [`include/AsyncInterval.hpp`](../../include/AsyncInterval.hpp) y
[`src/modules/AsyncInterval.cpp`](../../src/modules/AsyncInterval.cpp).

Temporizador no bloqueante basado en `millis()`. Permite ejecutar acciones cada
cierto intervalo sin detener el hilo principal ni usar `delay()`.

## API

| Método | Descripción |
| --- | --- |
| `AsyncInterval(unsigned long ms = 1000)` | Crea el temporizador con el intervalo indicado. |
| `bool ready()` | Devuelve `true` cuando transcurrió el intervalo y reinicia la referencia. |
| `unsigned long getInterval() const` | Devuelve el intervalo actual en milisegundos. |
| `void setInterval(unsigned long ms)` | Cambia el intervalo sin reiniciar el temporizador. |
| `void reset()` | Toma `millis()` como nueva referencia. |

## Ejemplo

Parpadeo de un LED cada 500 ms sin bloquear el resto del programa:

```cpp
#include <Arduino.h>
#include "AsyncInterval.hpp"

AsyncInterval parpadeo(500);
bool estadoLed = false;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    if (parpadeo.ready())
    {
        estadoLed = !estadoLed;
        digitalWrite(LED_BUILTIN, estadoLed ? HIGH : LOW);
    }

    // Otras tareas pueden ejecutarse aquí sin esperar.
}
```

## Notas

- `ready()` actualiza la referencia interna cada vez que devuelve `true`.
- La resta `currentTime - previousTime` funciona correctamente incluso cuando
  `millis()` se desborda, porque se usan enteros sin signo.
- Cambiar el intervalo con `setInterval()` no reinicia el temporizador; si
  necesitas empezar de cero, llama también a `reset()`.
