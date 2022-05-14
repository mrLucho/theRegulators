//
// Created by user on 14.05.2022.
//

#ifndef THEREGULATORS_REGULATOR_H
#define THEREGULATORS_REGULATOR_H

class Regulator{
    virtual float control(float setTemp,float currentTemp,float dt) = 0;
};
#endif //THEREGULATORS_REGULATOR_H
