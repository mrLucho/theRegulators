//
// Created by user on 14.05.2022.
//

#ifndef THEREGULATORS_REGULATORBB_H
#define THEREGULATORS_REGULATORBB_H

#include "regulator.h"

class RegulatorBB : Regulator{
public:


    float control(float setTemp, float currentTemp, float dt) override;
    float otherControl(float dt) override;
};
#endif //THEREGULATORS_REGULATORBB_H
