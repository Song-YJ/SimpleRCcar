#include "Arduino.h"
#include "Movement.h"

Movement::Movement(int RM1, int RM2, int LM1, int LM2)
{
    this->RM1 = RM1;
    this->RM2 = RM2;
    this->LM1 = LM1;
    this->LM2 = LM2;
}

void Movement::forward()
{
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
}

void Movement::left()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
 
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
}

void Movement::right()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);

    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}

void Movement::backward()
{
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH); 

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
}

void Movement::stop_()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);

    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}