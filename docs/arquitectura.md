# Arquitectura

## Objetivo

Mantener un `loop()` no bloqueante que mida la distancia de forma periódica y
actualice las salidas sin usar `delay()`. Cada módulo encapsula el hardware o
una regla de negocio concreta.

## Estructura de directorios

```text
.
├── include/
│   ├── AsyncInterval.hpp
│   ├── Buzzer.hpp
│   ├── Config.hpp
│   ├── Distancia.hpp
│   ├── HCSR04.hpp
│   ├── Led.hpp
│   └── Pantalla.hpp
├── src/
│   ├── main.cpp
│   └── modules/
│       ├── AsyncInterval.cpp
│       ├── Buzzer.cpp
│       ├── Distancia.cpp
│       ├── HCSR04.cpp
│       ├── Led.cpp
│       └── Pantalla.cpp
├── docs/
├── diagram.json
└── platformio.ini
```

## Capas

| Capa | Archivos | Responsabilidad |
| --- | --- | --- |
| Aplicación | `src/main.cpp` | Orquesta el ciclo de medición y las salidas. |
| Reglas de distancia | `Distancia.*` | Convierte cm a porcentaje, clasifica niveles y define el ritmo del buzzer. |
| Control de hardware | `Buzzer.*`, `Led.*`, `HCSR04.*`, `Pantalla.*` | Inicializan y manipulan cada componente. |
| Utilidades | `AsyncInterval.*` | Temporizador no bloqueante basado en `millis()`. |
| Configuración | `Config.hpp` | Pines, tiempos, umbrales y constantes. |

## Dependencias entre módulos

```text
main
├── AsyncInterval
├── Buzzer ──────┐
├── HCSR04 ──────┤
├── Led ─────────┼──> Config
├── Pantalla ────┘
│   └── Distancia ──> Config
└── Distancia
```

`Config.hpp` no depende de ningún módulo del proyecto. `Distancia` solo depende
de `Config`. Los módulos de hardware no se conocen entre sí.

## Flujo de datos

1. `HCSR04` entrega una distancia en centímetros o `-1.0f` si no hubo eco.
2. `Distancia` normaliza la lectura a un porcentaje de `0` a `100`.
3. El porcentaje se clasifica como `MuyCerca`, `Cerca`, `Moderado` o `Lejos`.
4. El nivel determina el intervalo del buzzer.
5. El porcentaje determina el color del LED.
6. El nivel y la distancia se muestran en la pantalla LCD.

## Decisiones de diseño

- **Sin `delay()` en el flujo principal.** `AsyncInterval` permite que la
  medición, el buzzer y la pantalla tengan ritmos independientes.
- **Configuración centralizada.** Los números mágicos viven en `Config.hpp`
  para evitar desincronizaciones entre módulos.
- **Una única clasificación.** `Distancia` concentra los umbrales; `main` y
  `Pantalla` no los duplican.
- **Lecturas inválidas tratadas como lejanas.** Si el sensor no recibe eco, el
  sistema se comporta como si no hubiera obstáculos, evitando falsos positivos
  de "muy cerca".
- **Refresco del LCD sin `clear()` continuo.** Las líneas se rellenan con
  espacios para borrar restos sin parpadeo.

## Recursos del microcontrolador

La compilación de referencia ocupa aproximadamente:

| Recurso | Uso |
| --- | --- |
| RAM | 587 bytes de 2048 (28.7 %) |
| Flash | 9772 bytes de 32256 (30.3 %) |
