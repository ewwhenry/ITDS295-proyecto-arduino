# Documentación del proyecto

Sistema de detección de proximidad para Arduino UNO. El proyecto mide la
distancia con un sensor ultrasónico HC-SR04 y responde con tres salidas:

- Un LED RGB cuyo color cambia según la cercanía.
- Un buzzer que se alterna con mayor o menor frecuencia.
- Una pantalla LCD 1602 I2C que muestra la distancia y el nivel.

## Índice

- [Arquitectura](arquitectura.md)
- [Hardware y conexiones](hardware.md)
- [Flujo del sistema](flujo.md)
- [Compilación y ejecución](compilacion.md)
- [Módulos](modules/AsyncInterval.md)
  - [AsyncInterval](modules/AsyncInterval.md)
  - [Buzzer](modules/Buzzer.md)
  - [Distancia](modules/Distancia.md)
  - [HCSR04](modules/HCSR04.md)
  - [Led](modules/Led.md)
  - [Pantalla](modules/Pantalla.md)

## Convenciones

| Magnitud | Unidad | Rango |
| --- | --- | --- |
| Distancia | centímetros (cm) | 0 a 400 |
| Distancia normalizada | porcentaje (%) | 0 a 100 |
| Tiempo | milisegundos (ms) | — |
| Frecuencia del buzzer | hercios (Hz) | 1000 por defecto |

Los niveles de cercanía se definen en [`include/Distancia.hpp`](../include/Distancia.hpp)
y los valores ajustables en [`include/Config.hpp`](../include/Config.hpp).

## Requisitos

- Arduino UNO
- PlatformIO IDE para VS Code
- Extensión Wokwi Simulator para la simulación
- Librería `marcoschwartz/LiquidCrystal_I2C`
