//
// Created by user on 14.05.2022.
//

#include "regulatorBB.h"



// returns controlled temp
float RegulatorBB::control(float dt) {
    if (roomPtr_ == nullptr or roomPtr_ == NULL) throw InvalidRoomPtr();
    if (heaterPtr_ == nullptr or heaterPtr_ == NULL) throw InvalidHeaterPtr();


    float currentTemp = roomPtr_->getTemperatura();
    float heaterPowerLevel =  (currentTemp < setTemp_) ? 1.0 : 0.0;
    float heat = this->heaterPtr_->giveHeat(heaterPowerLevel);
    this->roomPtr_->dodajCieplo(heat);
    roomPtr_->aktualizuj(dt);
    return roomPtr_->getTemperatura();
}
