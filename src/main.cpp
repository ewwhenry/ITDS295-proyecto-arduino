#include <Arduino.h>

/* Declaramos los pines como constantes para no hardcodear los datos. */
#define BUZZER_PIN 2
#define LED_PIN 3

/* Incializamos una variable de estado actual para saber cuando encender o apagar los componentes. */
int currentState = 0;

void setup()
{
    Serial.begin(9600);

    /* Configuramos los pines a modo salida (OUTPUT) para poder enviar pulsos a los componentes. */
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    if (currentState == 0)
    {
        /* Encendemos el led */
        digitalWrite(LED_PIN, HIGH);
        /* Hacemos sonar el buzzer */
        tone(BUZZER_PIN, 1000);
        /* Cambiamos el estado actual a 1 */
        currentState = 1;
    }
    else
    {
        /* Apagamos el led */
        digitalWrite(LED_PIN, LOW);
        /* Detenemos el sonido del buzzer */
        noTone(BUZZER_PIN);
        /* Cambiamos el estado actual a 0 */
        currentState = 0;
    }

    /* Esperamos 200ms */
    delay(200);
}