# Flujo del sistema

## `setup()`

1. Inicializa el puerto serie a `9600` baudios.
2. Inicializa el buzzer, el LED, el sensor HC-SR04 y la pantalla LCD.
3. Realiza una primera medición para mostrar un estado real desde el arranque.
4. Si la medición es inválida, usa `400 cm` como distancia.
5. Calcula porcentaje, nivel e intervalo del buzzer.
6. Establece el color del LED y actualiza la pantalla.

## `loop()`

El bucle principal ejecuta tres tareas independientes:

| Tarea | Intervalo | Acción |
| --- | --- | --- |
| Medición | 60 ms | Lee el HC-SR04, recalcula porcentaje y nivel, ajusta el buzzer y actualiza el LED. |
| Buzzer | Según el nivel | Alterna el sonido y escribe el estado por el puerto serie. |
| Pantalla | 250 ms | Redibuja la distancia y el nivel en el LCD. |

El intervalo de 60 ms es el tiempo mínimo recomendado entre lecturas del
HC-SR04 para evitar ecos residuales.

## Niveles y respuestas

| Porcentaje | Distancia aproximada | Nivel | LED | Intervalo del buzzer |
| --- | --- | --- | --- | --- |
| 75–100 % | 300–400 cm | `Lejos` | Verde | 750 ms |
| 50–74 % | 200–299 cm | `Moderado` | Amarillo | 500 ms |
| 25–49 % | 100–199 cm | `Cerca` | Naranja | 250 ms |
| 0–24 % | 0–99 cm | `MuyCerca` | Rojo | 50 ms |

El intervalo inicial del objeto `buzzerInterval` es de `1000 ms`, pero se
reemplaza en `setup()` por el intervalo correspondiente al nivel medido.

## Gradiente del LED

`obtenerColor()` interpola linealmente entre tres puntos:

| Porcentaje | Color | RGB aproximado |
| --- | --- | --- |
| 0 % | Rojo | (255, 0, 0) |
| 50 % | Amarillo | (255, 255, 0) |
| 100 % | Verde | (0, 255, 0) |

## Lecturas inválidas

`medirDistanciaHCSR04()` devuelve `-1.0f` cuando `pulseIn` no detecta eco
dentro de `30000 µs`. `main.cpp` convierte ese valor en `400 cm`, por lo que el
sistema reporta `Lejos` y mantiene el LED en verde.

## Puerto serie

Cada vez que el buzzer cambia de estado se imprime una línea:

```text
Estado del buzzer: Encendido
Estado del buzzer: Apagado
```
