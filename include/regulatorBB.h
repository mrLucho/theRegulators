//
// Created by user on 14.05.2022.
//

#ifndef THEREGULATORS_REGULATORBB_H
#define THEREGULATORS_REGULATORBB_H

#include "regulator.h"





class RegulatorBB : public Regulator{
public:
    RegulatorBB() = default;
    RegulatorBB(float desiredTemp,Pomieszczenie* roomPtr,Heater* heaterPtr) : Regulator(desiredTemp, roomPtr,heaterPtr) {}

    float control(float dt) override;

};
#endif //THEREGULATORS_REGULATORBB_H
