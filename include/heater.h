//
// Created by user on 14.05.2022.
//

#ifndef THEREGULATORS_HEATER_H
#define THEREGULATORS_HEATER_H

#include <iostream>
#include <exception>


struct InvalidPowerLevel : public std::exception{
    const char * what () const throw (){
        return "not in range(0,1)";
    }
};

class Heater{
public:
    Heater(float maxPower):maxPower_(maxPower) { if (maxPower <=0 ) throw InvalidPowerLevel(); };
    float getMaxPower(){return maxPower_;}
// in case of invalid input full power, the regulator will withstand
// todo: consider to throw exc for invalid power level
    float giveHeat(float powerLevel){ if(powerLevel<0)throw InvalidPowerLevel();  return (powerLevel <= 1 && powerLevel >= 0) ? powerLevel * maxPower_ : maxPower_;}

    void works(){std::cout<<"heater works";}

private:
    const float maxPower_;
};
#endif //THEREGULATORS_HEATER_H
