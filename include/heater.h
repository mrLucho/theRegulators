//
// Created by user on 14.05.2022.
//

#ifndef THEREGULATORS_HEATER_H
#define THEREGULATORS_HEATER_H

class Heater{
public:
    Heater(float maxPower):maxPower_(maxPower) {};
    float getMaxPower(){return maxPower_;}
    float getPowerLevel(){return powerLevel;}
    void setPowerLevel(float power); //sets frac powerLevel to match desired power on heater

    float giveHeat(){return powerLevel * maxPower_;}

private:
    const float maxPower_;
    float powerLevel;
};
#endif //THEREGULATORS_HEATER_H
