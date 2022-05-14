//
// Created by user on 12.05.2022.
//

#ifndef THEREGULATORS_SIMULATION_H
#define THEREGULATORS_SIMULATION_H
#include <cstdio>
#include <vector>
#include <string>

#include "regulatorBB.h"



// main class, lots of inputs here to avoid it later
class Simulation{
public:
    Simulation(float dtime,float heaterMaxPower,float height,float width,float deep,float setTemp = 20);
    void setRegulator(bool isBB);

    void iteration();
    void save2file(std::string filename);
    void run(int iterations=10);

    Heater heater;
    Pomieszczenie room;
    ~Simulation(){delete regulator[0];}

private:
    const float dt; //float to be compatible with pomieszczenie class
    std::vector<float> tempLog;


    std::vector<Regulator*>regulator;
    float setTemp_;

};
#endif //THEREGULATORS_SIMULATION_H
