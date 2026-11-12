# Pantalla

Archivo: [`include/Pantalla.hpp`](../../include/Pantalla.hpp) y
[`src/modules/Pantalla.cpp`](../../src/modules/Pantalla.cpp).

Controla un LCD 1602 con módulo I2C. La dirección por defecto es `0x27` y la
comunicación usa `Wire` con SDA en `A4` y SCL en `A5`.

## API

| Función | Descripción |
| --- | --- |
| `void inicializarPantalla()` | Inicializa el LCD, enciende la retroiluminación y limpia la pantalla. |
| `void mostrarEstadoSistema(float distanciaCm, NivelDistancia nivel)` | Muestra la distancia y el nombre del nivel. |

## Formato de pantalla

```text
Dist: 123.4 cm
Moderado
```

- La primera línea muestra la distancia en centímetros con un decimal.
- La segunda línea muestra el nivel de cercanía.
- Las líneas se rellenan con espacios para borrar caracteres anteriores sin
  usar `lcd.clear()` en cada refresco.
- Si la distancia es negativa, se muestra `400.0 cm`.

## Ejemplo

```cpp
#include "Pantalla.hpp"

void setup()
{
    inicializarPantalla();
    mostrarEstadoSistema(150.0f, NivelDistancia::Cerca);
}
```

## Notas

- El refresco se realiza cada `250 ms` desde `main.cpp` para evitar parpadeo.
- Algunos módulos LCD usan la dirección `0x3F`. Si la pantalla no responde,
  cambia `config::LCD_DIRECCION` en [`include/Config.hpp`](../../include/Config.hpp).
- El objeto `LiquidCrystal_I2C` es privado del archivo `.cpp`; el resto del
  proyecto solo usa la interfaz pública.
