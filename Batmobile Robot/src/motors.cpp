#include <Arduino.h>
#include "motors.h"

Motors::Motors(PinList pins)
    : pins(pins)        // initialize pins
{
}

void Motors::begin()
{
    // set pins as outputs
    pinMode(pins.in1, OUTPUT);
    pinMode(pins.in2, OUTPUT);
    pinMode(pins.in3, OUTPUT);
    pinMode(pins.in4, OUTPUT);
}

void Motors::move(Commands cmd, int sec)
{
    // move motors according to cmd
}