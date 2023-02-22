#ifndef MOTORS_H
#define MOTORS_H

/* Library for moving the robot */

class Motors {
    public:
        enum class Commands {forward, left, right, redo};           // list of available commands
        struct PinList { int in1; int in2; int in3; int in4; };     // list of pins for driving motors

        Motors() = delete;
        Motors(PinList pins);
        void begin();           // set pin modes
        void move(Commands cmd, int sec);   // move the robot according to the command for specified time

    private:
        PinList pins;        // structure containing four pins in1, in2, in3 and in4
        Commands prev_move;  // keeps track of the previous move
};

#endif 