#include "HCSR04.hpp"
#include <Arduino.h>

#define TRIGGER_PIN 7
#define ECHO_PIN 8

void inicializarHCSR04()
{
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
};

float medirDistanciaHCSR04()
{
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = duration * 0.034 / 2; // Convert to centimeters
    return distance;
}