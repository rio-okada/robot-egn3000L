#include <Arduino.h>
#include "ir_sensor.h"

IR::IR(int pin)
    : pin(pin)
{
}

void IR::begin()
{
    pinMode(pin, INPUT);
}

bool IR::detectObject()
{
    // will implement later
    return true;
}