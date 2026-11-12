# HCSR04

Archivo: [`include/HCSR04.hpp`](../../include/HCSR04.hpp) y
[`src/modules/HCSR04.cpp`](../../src/modules/HCSR04.cpp).

Controla el sensor ultrasónico HC-SR04 conectado a `TRIG = D7` y `ECHO = D8`.

## API

| Función | Descripción |
| --- | --- |
| `void inicializarHCSR04()` | Configura TRIG como salida, ECHO como entrada y deja TRIG en bajo. |
| `float medirDistanciaHCSR04()` | Envía un pulso de 10 µs y devuelve la distancia en cm, o `-1.0f` si no hay eco. |

## Funcionamiento

1. Se pone TRIG en bajo durante 2 µs.
2. Se genera un pulso alto de 10 µs en TRIG.
3. `pulseIn()` mide la duración del pulso alto en ECHO con un timeout de
   `30000 µs`.
4. La distancia se calcula con:

```text
distancia_cm = duración_µs × 0.0343 / 2
```

El factor `0.0343` corresponde a la velocidad del sonido en cm/µs y la división
entre 2 compensa el viaje de ida y vuelta.

## Ejemplo

```cpp
#include "HCSR04.hpp"

void setup()
{
    Serial.begin(9600);
    inicializarHCSR04();
}

void loop()
{
    float distancia = medirDistanciaHCSR04();

    if (distancia < 0.0f)
    {
        Serial.println("Sin eco");
    }
    else
    {
        Serial.print(distancia);
        Serial.println(" cm");
    }

    delay(60);
}
```

## Notas

- El intervalo mínimo recomendado entre mediciones es de `60 ms`.
- `-1.0f` indica que no se recibió eco dentro del timeout; el llamador decide
  cómo tratarlo.
- El sensor tiene un alcance práctico de aproximadamente `2 cm` a `400 cm`.
