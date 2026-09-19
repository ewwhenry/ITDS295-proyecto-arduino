## AsyncInterval.cpp

Esta clase sirve para poder ejecutar un conjunto de instrucciones en un determinado intervalo de tiempo sin detener el hilo actual.

Esto gracias a no depender de la funcion `delay()` de arduino.

### Modo de uso

Esto hace sonar el buzzer cada 100 milisegundos.

`main.cpp`
```cpp
#include <Arduino.h>
#include "AsyncInterval.hpp"

AsyncInterval sonarBuzzer(100);

void setup ()
{
    pinMode(8, OUTPUT); 
}

void loop ()
{
    if (sonarBuzzer.ready()) {
        tone(8, 1000);
    }
}
```