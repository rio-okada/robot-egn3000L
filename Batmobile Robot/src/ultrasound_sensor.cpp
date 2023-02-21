#include <Arduino.h>
#include "ultrasound_sensor.h"

Ultrasound::Ultrasound(int triggerPin, int echoPin)
    : triggerPin(triggerPin), echoPin(echoPin)      // set pins
{ 
}

void Ultrasound::begin()
{
    pinMode(triggerPin, OUTPUT);    // set trigger pin as output
    pinMode(echoPin, INPUT);        // set echo pin as input
}

int Ultrasound::getDistance()
{
    // will implement later
    return 0;
}