#include "Pantalla.hpp"

#include "Config.hpp"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <stdio.h>
#include <string.h>

LiquidCrystal_I2C lcd(config::LCD_DIRECCION, config::LCD_COLUMNAS, config::LCD_FILAS);

namespace
{
void rellenarLinea(char *linea)
{
    size_t longitud = strlen(linea);

    while (longitud < config::LCD_COLUMNAS)
    {
        linea[longitud++] = ' ';
    }

    linea[longitud] = '\0';
}

void imprimirLinea(uint8_t fila, char *linea)
{
    rellenarLinea(linea);
    lcd.setCursor(0, fila);
    lcd.print(linea);
}
} // namespace

void inicializarPantalla()
{
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void mostrarEstadoSistema(float distanciaCm, NivelDistancia nivel)
{
    if (distanciaCm < 0.0f)
    {
        distanciaCm = config::DISTANCIA_MAXIMA_CM;
    }

    int centimetros = static_cast<int>(distanciaCm);
    int decimas = static_cast<int>((distanciaCm - centimetros) * 10.0f + 0.5f);

    if (decimas >= 10)
    {
        centimetros++;
        decimas = 0;
    }

    char lineaDistancia[config::LCD_COLUMNAS + 1];
    snprintf(lineaDistancia, sizeof(lineaDistancia), "Dist: %d.%d cm", centimetros, decimas);
    imprimirLinea(0, lineaDistancia);

    char lineaNivel[config::LCD_COLUMNAS + 1];
    snprintf(lineaNivel, sizeof(lineaNivel), "%s", nombreNivel(nivel));
    imprimirLinea(1, lineaNivel);
}
