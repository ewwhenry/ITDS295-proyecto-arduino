# Compilación y ejecución

## Requisitos

- [Visual Studio Code](https://code.visualstudio.com/Download)
- Extensión [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
- Extensión [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)
- PlatformIO Core (`pio`) disponible en la terminal

La única dependencia externa es la librería
[`marcoschwartz/LiquidCrystal_I2C`](https://registry.platformio.org/libraries/marcoschwartz/LiquidCrystal_I2C),
declarada en `platformio.ini`. PlatformIO la instala automáticamente.

## Compilar

```bash
pio run
```

El firmware se genera en `.pio/build/uno/firmware.hex`.

## Subir al Arduino

```bash
pio run -t upload
```

## Monitor serie

```bash
pio device monitor
```

La velocidad configurada es `9600` baudios.

## Simular con Wokwi

1. Abre el proyecto en VS Code.
2. Ejecuta el comando `Wokwi: Start Simulator`.
3. El firmware usado por Wokwi se toma de `.pio/build/uno/firmware.hex` y
   `.pio/build/uno/firmware.elf`, según `wokwi.toml`.

## Solución de problemas

| Síntoma | Posible causa | Solución |
| --- | --- | --- |
| El LCD no muestra nada | Dirección I2C incorrecta o contraste bajo | Prueba `0x3F` en `Config.hpp` o ajusta el potenciómetro del módulo. |
| El LCD muestra caracteres extraños | Mala conexión SDA/SCL | Verifica A4 (SDA) y A5 (SCL). |
| El sensor siempre reporta lejos | Sin eco o timeout | Revisa TRIG en D7, ECHO en D8 y la alimentación del sensor. |
| El buzzer no suena | Pin incorrecto o volumen bajo | Verifica D2 y el volumen del componente en Wokwi. |
| El LED muestra colores mezclados | Cátodo común mal conectado | El pin COM debe ir a GND. |
| No hay salida serie | Monitor a otra velocidad | Usa `9600` baudios. |
