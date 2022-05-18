//
// Created by user on 18.05.2022.
//

#ifndef THEREGULATORS_PIDREGULATOR_H
#define THEREGULATORS_PIDREGULATOR_H
#include "regulator.h"

class PID : public Regulator{
    float control(float dt) override;


public:
    PID(float desiredTemp,Pomieszczenie* roomPtr,Heater* heaterPtr,float kp,float ki,float kd) :
    Regulator(desiredTemp, roomPtr,heaterPtr), kd_(kd),ki_(ki),kp_(kp){}

private:
    float integral;
    float previousE; // for derivative
    float kp_;
    float ki_;
    float kd_;
};
#endif //THEREGULATORS_PIDREGULATOR_H
