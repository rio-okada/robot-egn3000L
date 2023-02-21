#include <Arduino.h>

#include "ultrasound_sensor.h"
#include "ir_sensor.h"

Ultrasound proximity_sensor(9, 8);     // ultrasonic sensor with triggerPin = 9 and echoPin = 8
IR ir_sensor1(1);   // connect to pin 1
IR ir_sensor2(4);   // connect to pin 4

void setup() {
  // begin() functions set pinModes
  proximity_sensor.begin();
  ir_sensor1.begin();
  ir_sensor2.begin();
}

void loop() {
  
}