#include "Display.hpp"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void iniciarDisplay()
{
    lcd.init();
    lcd.backlight();
}

void mostrarDisplay(String content, unsigned int row, unsigned int column)
{
    lcd.setCursor(column, row);
    lcd.print(content);
}

void limpiarDisplay()
{
    lcd.clear();
}