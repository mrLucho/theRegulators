//
// Created by user on 12.05.2022.
//

#ifndef THEREGULATORS_SIMULATION_H
#define THEREGULATORS_SIMULATION_H
#include <cstdio>
#include <vector>
#include <string>

#include "regulatorBB.h"




class Simulation{
public:
    Simulation(float dtime,float heaterMaxPower,float height,float width,float deep,float setTemp = 20);
    void setRegulator(bool isBB);

    void iteration(float dt);
    void save2file(std::string filename);
    void run(float dt,int iterations=10);

    Heater heater;
    Pomieszczenie room;
    ~Simulation(){regulator.clear();}

private:
    const float dt; //float to be compatible with pomieszczenie class
    std::vector<float> tempLog;


    std::vector<Regulator*>regulator;
    float setTemp_;

};
#endif //THEREGULATORS_SIMULATION_H
