#ifndef IR_H
#define IR_H

class IR {
    public:
        IR() = delete;
        IR(int pin);    // pin = Arduino pin nubmer to connect IR sensor
        void begin();   // set pin modes
        bool detectObject();    // returns true if object is detected. false otherwise

    private:
        int pin;    // arduino pin number that IR sensor is connected to
};

#endif IR_H