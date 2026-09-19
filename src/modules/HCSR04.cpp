#include "HCSR04.hpp"
#include <Arduino.h>

unsigned const int HCSR04_TRIG_PIN = 3;
unsigned const int HCSR04_ECHO_PIN = 2;

void inicializarHCSR04()
{
    pinMode(HCSR04_TRIG_PIN, OUTPUT);
    pinMode(HCSR04_ECHO_PIN, INPUT);
}

void iniciarHCSR04()
{
    digitalWrite(HCSR04_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(HCSR04_TRIG_PIN, LOW);
}

float leerHCSR04()
{
    iniciarHCSR04();

    float raw_distance = pulseIn(HCSR04_ECHO_PIN, HIGH);
    float distance_cm = raw_distance / 58;

    return distance_cm;
}