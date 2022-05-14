//
// Created by user on 12.05.2022.
//

#include <iostream>
#include "simulation.h"
#include <vector>
//
void Simulation::iteration(float dt) {

    std::cout<<(regulator[0])->otherControl(dt)<<std::endl;
}

void Simulation::save2file(std::string filename) {

}

void Simulation::run( float dt,int iterations) {
    for (int i = 0; i < iterations; ++i) {
        iteration(dt);
    }
}

void Simulation::setRegulator(bool isBB) {
    if (isBB){
        RegulatorBB* regPtr = new RegulatorBB();
        this->regulator.push_back(regPtr);
    }
}
Simulation::Simulation(float dtime,float heaterMaxPower,float height,float width,float deep,float setTemp)
        : dt(dtime), room(height,width,deep),heater(heaterMaxPower),setTemp_(setTemp){
    if (true){
        RegulatorBB* regPtr = new RegulatorBB(setTemp, &(this->room),&(this->heater));
        this->regulator.push_back(regPtr);
    }
}