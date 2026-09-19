#include "RGBLed.hpp"

#include <Arduino.h>

unsigned int RED_PIN = 9;
unsigned int GREEN_PIN = 10;
unsigned int BLUE_PIN = 6;

void inicializarRGB()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void establecerRGB(unsigned int red, unsigned int green, unsigned int blue)
{
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}