#pragma once
#include <Arduino.h>

void iniciarDisplay();
void mostrarDisplay(String content, unsigned int row = 0, unsigned int column = 0);
void limpiarDisplay();