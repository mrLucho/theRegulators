//
// Created by user on 12.05.2022.
//

#ifndef THEREGULATORS_SIMULATION_H
#define THEREGULATORS_SIMULATION_H
#include <stdio.h>
#include <vector>
#include <string>

#include "heater.h"
#include "pomieszczenie.h"




class Simulation{
public:
    Simulation(float dtime,float heaterMaxPower,float height,float width,float deep)
    : dt(dtime), room(height,width,deep),heater(heaterMaxPower){};


    void iteration(float dt);
    void save2file(std::string filename);
    void run(int iterations, float dt);

private:
    const float dt; //float to be compatible with pomieszczenie class
    std::vector<float> tempLog;

    Heater heater;
    Pomieszczenie room;

};
#endif //THEREGULATORS_SIMULATION_H
