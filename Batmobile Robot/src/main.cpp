#include <Arduino.h>

#include "ultrasound_sensor.h"
#include "ir_sensor.h"
#include "motors.h"

/* Initialize objects and define some constants */
Ultrasound proximity_sensor(9, 8);     // ultrasonic sensor with triggerPin = 9 and echoPin = 8
IR ir_right(1);     // connect to pin 1
IR ir_left(4);      // connect to pin 4
Motors motors({5, 6, 7, 10});   // use pins 5, 6, 7, 10 to drive motors
const int move_time = 3;  // how long in sec to move the robot each iteration.

void setup() {
  // begin() functions set pinModes
  proximity_sensor.begin();
  ir_right.begin();
  ir_left.begin();
  motors.begin();
}

void loop() {
  /* if the object in front is closer than 5cm, do nothing. */
  if (proximity_sensor.getDistance() < 5) {
    return;
  }

  /* Using the two IR sensors, determine what the robot should do */
  bool object_left = ir_left.detectObject();    // true if object is detected by the IR sensor on the left
  bool object_right = ir_right.detectObject();  // same but for the left sensor
  

  if (object_left && object_right) {
    // if both sensors detect object, move straight.
    motors.move(Motors::Commands::forward, move_time);
  }
  else if (object_left && !object_right) {
    // if right sensor is not detecting anything, turn right
    motors.move(Motors::Commands::right, move_time);
  }
  else if (!object_left && object_right) {
    // if left sensor is not detecting anything, turn left
    motors.move(Motors::Commands::left, move_time);
  }
  else {
    // if neither is detecting anything it's kind of stuck, so undo the last move and move again but with half the move_time
    motors.move(Motors::Commands::redo, move_time);
  }
}