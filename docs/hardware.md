# Hardware y conexiones

## Componentes

| Componente | Uso |
| --- | --- |
| Arduino UNO | Microcontrolador principal. |
| Protoboard | Distribución de alimentación y conexiones. |
| Buzzer | Salida sonora intermitente. |
| LED RGB (cátodo común) | Indicador visual del nivel de cercanía. |
| LCD 1602 con módulo I2C | Visualización de distancia y nivel. |
| HC-SR04 | Sensor ultrasónico de distancia. |

## Tabla de conexiones

| Componente | Pin del componente | Pin del Arduino UNO |
| --- | --- | --- |
| Buzzer | Positivo | D2 |
| Buzzer | Negativo | GND |
| LED RGB | R | D9 (PWM) |
| LED RGB | G | D5 (PWM) |
| LED RGB | B | D6 (PWM) |
| LED RGB | COM (cátodo) | GND |
| LCD 1602 I2C | VCC | 5V |
| LCD 1602 I2C | GND | GND |
| LCD 1602 I2C | SDA | A4 |
| LCD 1602 I2C | SCL | A5 |
| HC-SR04 | VCC | 5V |
| HC-SR04 | GND | GND |
| HC-SR04 | TRIG | D7 |
| HC-SR04 | ECHO | D8 |

La dirección I2C configurada para el LCD es `0x27`. Algunos módulos usan
`0x3F`; si la pantalla no responde, ajusta `config::LCD_DIRECCION` en
[`include/Config.hpp`](../include/Config.hpp).

## Notas de montaje

- El LED RGB debe ser de **cátodo común**: el cátodo va a GND y cada canal se
  enciende con una señal positiva.
- Los pines D9, D5 y D6 son PWM, necesarios para generar los colores
  intermedios del LED.
- El canal rojo usa D9 en lugar de D3 porque `tone()` ocupa el Timer2 del
  Arduino UNO, que también controla el PWM de D3 y D11.
- El HC-SR04 se alimenta a 5 V. Su salida ECHO es compatible con el Arduino
  UNO.
- El diagrama de Wokwi no incluye resistencias limitadoras para el LED ni
  potenciómetro de contraste. En un montaje físico, agrega resistencias para
  cada canal del LED y verifica el contraste del LCD.
- Mantén el sensor separado de fuentes de ruido y evita obstáculos blandos que
  absorban el ultrasonido.

## Diagrama

El circuito está definido en [`diagram.json`](../diagram.json) y puede
simularse con la extensión Wokwi desde VS Code.
