#ifndef Movement_h
#define Movement_h
#include "Arduino.h"

class Movement{
    public:
    Movement(int RM1, int RM2, int LM1, int LM2);
    void forward();
    void left();
    void right();
    void backward();
    void stop_();

    private:
    int RM1, RM2, LM1, LM2;
};

#endif