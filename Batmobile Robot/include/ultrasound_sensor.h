#ifndef ULTRASOUND_H
#define ULTRASOUND_H

class Ultrasound {
    public:
        Ultrasound() = delete;
        Ultrasound(int triggerPin, int echoPin);
        void begin();       // sets pinMode
        int getDistance();  // triggers the sensor and returns distance in cm
    private:
        int triggerPin;     // pin number for trigger 
        int echoPin;        // pin number for echo
};

#endif