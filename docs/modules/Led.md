# Led

Archivo: [`include/Led.hpp`](../../include/Led.hpp) y
[`src/modules/Led.cpp`](../../src/modules/Led.cpp).

Controla un LED RGB de cátodo común conectado a los pines PWM `D9` (rojo),
`D5` (verde) y `D6` (azul).

## API

| Función | Descripción |
| --- | --- |
| `void inicializarLed()` | Configura los tres canales como salida y apaga el LED. |
| `void encenderLed()` | Enciende todos los canales. |
| `void apagarLed()` | Apaga todos los canales. |
| `void alternarLed(bool &estadoLed)` | Alterna encendido/apagado usando una referencia de estado. |
| `void establecerColorPorcentaje(int porcentaje)` | Aplica el color correspondiente a un porcentaje de distancia. |
| `RGB obtenerColor(int porcentaje)` | Calcula los componentes RGB para el porcentaje. |

## Estructura `RGB`

```cpp
struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};
```

## Gradiente de color

| Porcentaje | Color |
| --- | --- |
| `0 %` | Rojo `(255, 0, 0)` |
| `50 %` | Amarillo `(255, 255, 0)` |
| `100 %` | Verde `(0, 255, 0)` |

La transición es lineal en dos tramos: rojo → amarillo y amarillo → verde.

## Ejemplo

```cpp
#include "Led.hpp"

void setup()
{
    inicializarLed();
}

void loop()
{
    establecerColorPorcentaje(50);
    delay(500);

    establecerColorPorcentaje(100);
    delay(500);
}
```

## Notas

- Los pines usados deben soportar PWM; por eso se eligieron D9, D5 y D6.
- El rojo se movió de D3 a D9 porque `tone()` usa el Timer2 del Arduino UNO,
  que controla el PWM de D3 y D11. Así se evita que el buzzer interfiera con
  el canal rojo del LED.
- El porcentaje se satura automáticamente al rango `0–100`.
- El LED debe ser de cátodo común; el cátodo va a GND.
