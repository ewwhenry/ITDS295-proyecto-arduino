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
    switch (distancia)
    {
        case 4: 
            lcd.print("Lejos"); 
            break;
        case 3: 
            lcd.print("Moderado"); 
            break;
        case 2: 
            lcd.print("Cerca"); 
            break;
        case 1: 
            lcd.print("Muy cerca"); 
            break;
        default: 
            lcd.print("Desconocido"); 
            break;
    }
}