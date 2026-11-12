# Buzzer

Archivo: [`include/Buzzer.hpp`](../../include/Buzzer.hpp) y
[`src/modules/Buzzer.cpp`](../../src/modules/Buzzer.cpp).

Controla un buzzer pasivo conectado al pin `D2`. La frecuencia se configura en
`config::FRECUENCIA_BUZZER_HZ` (`1000 Hz` por defecto).

## API

| Función | Descripción |
| --- | --- |
| `void inicializarBuzzer()` | Configura el pin como salida y deja el buzzer apagado. |
| `void activarBuzzer(int frecuenciaHz)` | Emite un tono con la frecuencia indicada. |
| `void desactivarBuzzer()` | Detiene el tono y deja el pin en nivel bajo. |
| `void alternarBuzzer(bool &estadoBuzzer, int frecuenciaHz)` | Alterna entre encendido y apagado usando una referencia de estado. |

## Ejemplo

```cpp
#include "Buzzer.hpp"

bool encendido = false;

void setup()
{
    inicializarBuzzer();
}

void loop()
{
    alternarBuzzer(encendido, 1000);
    delay(500);
}
```

> En el proyecto real no se usa `delay()`; el ritmo lo controla
> [`AsyncInterval`](AsyncInterval.md).

## Notas

- La función `tone()` usa un temporizador interno del microcontrolador.
- Si el buzzer es activo (con oscilador propio), `tone()` puede no producir el
  efecto esperado; el proyecto asume un buzzer pasivo.
- El estado se pasa por referencia para que la función pueda actualizarlo.
