
#include "regulatorBB.h"



// returns controlled temp
float RegulatorBB::control(float dt) {
    if (roomPtr_ == nullptr or roomPtr_ == NULL) throw InvalidRoomPtr();
    if (heaterPtr_ == nullptr or heaterPtr_ == NULL) throw InvalidHeaterPtr();


    float currentTemp = roomPtr_->getTemperatura();
    float heaterPowerLevel =  (currentTemp < setTemp_) ? 1.0 : 0.0;
    heaterPtr_->setCurrentLevel(heaterPowerLevel);
    float heat = this->heaterPtr_->giveHeat(heaterPowerLevel);
    this->roomPtr_->dodajCieplo(heat);
    roomPtr_->aktualizuj(dt);
    return roomPtr_->getTemperatura();
}
