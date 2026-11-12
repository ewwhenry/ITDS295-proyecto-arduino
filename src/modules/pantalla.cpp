#include "pantalla.hpp"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//(Dirección 0x27, 16 columnas, 2 filas)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void inicializarPantalla()
{
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void mostrarEstadoSistema(int distancia)
{
    lcd.clear();

    // Fila 0: Muestra la distancia numerica
    lcd.setCursor(0, 0);
    lcd.print("Distancia: ");
    lcd.print(distancia);

    // Fila 1: Muestra la distancia en palabras
    lcd.setCursor(0, 1);
    if (distancia >= 75)
    {
        lcd.print("Lejos");
    }
    else if (distancia >= 50)
    {
        lcd.print("Moderado");
    }
    else if (distancia >= 25)
    {
        lcd.print("Cerca");
    }
    else
    {
        lcd.print("Muy cerca");
    }
}