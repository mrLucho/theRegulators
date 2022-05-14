//
// Created by user on 14.05.2022.
//

#ifndef THEREGULATORS_REGULATOR_H
#define THEREGULATORS_REGULATOR_H

#include "pomieszczenie.h"
#include "heater.h"

class Regulator{
    Regulator() = default;
    Regulator(float desiredTemp,Pomieszczenie* roomPtr,Heater* heaterPtr)
    : setTemp_(desiredTemp),roomPtr_(roomPtr),heaterPtr_(heaterPtr){}

    void setParameters(float desiredTemp,Pomieszczenie* roomPtr,Heater* heaterPtr){
        setTemp_ =desiredTemp;
        roomPtr_=roomPtr;
        roomPtr_=roomPtr;
    }

    virtual float control(float setTemp,float currentTemp,float dt) = 0;
    virtual float otherControl(float dt) = 0;

protected:
    float setTemp_;
    Pomieszczenie* roomPtr_;
    Heater* heaterPtr_;
};
#endif //THEREGULATORS_REGULATOR_H
