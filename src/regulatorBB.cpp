//
// Created by user on 14.05.2022.
//

#include "regulatorBB.h"
// returns power level
float RegulatorBB::control(float setTemp, float currentTemp, float dt) {
    return (currentTemp<setTemp) ? 1 : 0.0;
}
// returns controlled temp
float RegulatorBB::otherControl(float dt) {
//   todo: trow error for <-273C
    float currentTemp = roomPtr_->getTemperatura();
    float heaterPowerLevel =  (currentTemp< setTemp_) ? 1 : 0.0;
    float heat = this->heaterPtr_->giveHeat(heaterPowerLevel);
    this->roomPtr_->dodajCieplo(heat);
    roomPtr_->aktualizuj(dt);
    return roomPtr_->getTemperatura();
}
