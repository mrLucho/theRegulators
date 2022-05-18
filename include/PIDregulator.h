#ifndef THEREGULATORS_PIDREGULATOR_H
#define THEREGULATORS_PIDREGULATOR_H
#include "regulator.h"

class PID : public Regulator{
public:
    float control(float dt) override;

    PID(float desiredTemp,Pomieszczenie* roomPtr,Heater* heaterPtr,float kp,float ki,float kd) :
    Regulator(desiredTemp, roomPtr,heaterPtr), kd_(kd),ki_(ki),kp_(kp){}

private:
    float integral_=0;
    float previousE_=0; // for derivative
    const float kp_;
    const float ki_;
    const float kd_;
};
#endif //THEREGULATORS_PIDREGULATOR_H
