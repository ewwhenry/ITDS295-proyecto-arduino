# Distancia

Archivo: [`include/Distancia.hpp`](../../include/Distancia.hpp) y
[`src/modules/Distancia.cpp`](../../src/modules/Distancia.cpp).

Concentra la conversión de centímetros a porcentaje, la clasificación por
niveles y el intervalo del buzzer asociado.

## Niveles

```cpp
enum class NivelDistancia
{
    MuyCerca,
    Cerca,
    Moderado,
    Lejos
};
```

## API

| Función | Descripción |
| --- | --- |
| `int porcentajeDesdeDistancia(float distanciaCm)` | Normaliza `0–400 cm` a `0–100 %`. Una lectura negativa devuelve `100`. |
| `NivelDistancia nivelDesdePorcentaje(int porcentaje)` | Clasifica el porcentaje en un nivel. |
| `const char *nombreNivel(NivelDistancia nivel)` | Devuelve `"Muy cerca"`, `"Cerca"`, `"Moderado"` o `"Lejos"`. |
| `unsigned long intervaloBuzzer(NivelDistancia nivel)` | Devuelve el intervalo de alternancia del buzzer. |

## Umbrales

| Porcentaje | Nivel | Intervalo del buzzer |
| --- | --- | --- |
| `>= 75` | `Lejos` | `750 ms` |
| `>= 50` | `Moderado` | `500 ms` |
| `>= 25` | `Cerca` | `250 ms` |
| `< 25` | `MuyCerca` | `50 ms` |

Los valores están definidos en [`include/Config.hpp`](../../include/Config.hpp).

## Ejemplo

```cpp
#include "Distancia.hpp"

float distanciaCm = 180.0f;

int porcentaje = porcentajeDesdeDistancia(distanciaCm);
NivelDistancia nivel = nivelDesdePorcentaje(porcentaje);
unsigned long intervalo = intervaloBuzzer(nivel);
```

## Notas

- La distancia máxima del HC-SR04 se toma como `400 cm`.
- El porcentaje se trunca a entero para simplificar la clasificación y la
  visualización.
- Las lecturas inválidas se tratan como lejanas para no generar falsas
  alarmas.
