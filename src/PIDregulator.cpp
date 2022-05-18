#include "PIDregulator.h"
float PID::control(float dt) {
    if (roomPtr_ == nullptr) throw InvalidRoomPtr();
    if (heaterPtr_ == nullptr) throw InvalidHeaterPtr();
    float e = this->setTemp_ - roomPtr_->getTemperatura();
    integral_ += e * dt;
    float deltaE = (e - previousE_) / dt;
    previousE_ = e;

    float heaterPowerLevel = kp_ * e + ki_ * integral_ + kd_ * deltaE;

    if (heaterPowerLevel >=1) heaterPowerLevel=1;
    if (heaterPowerLevel <=0) heaterPowerLevel=0;
    heaterPtr_->setCurrentLevel(heaterPowerLevel);
    float heat = this->heaterPtr_->giveHeat(heaterPowerLevel);
    this->roomPtr_->dodajCieplo(heat);
    roomPtr_->aktualizuj(dt);

    return roomPtr_->getTemperatura();
}