//
// Created by user on 12.05.2022.
//

#include <iostream>
#include "simulation.h"
#include <vector>
#include <fstream>

//
void Simulation::iteration() {
    float temp;
    if (regulator.empty() or regulator[0] == nullptr) throw NoRegulatorPresent();
    try {
          temp= (regulator[0])->control(dt);
    }
    catch (NoRegulatorPresent& noRegulatorPresent) {
        std::cout<<noRegulatorPresent.what()<<std::endl;
    }

    if (temp < -273.15) throw TooLowTemp();
    tempLog.push_back(temp);
    std::cout<<temp<<std::endl;
}

void Simulation::save2file(std::string filename) {
    std::ofstream outFile(filename);
    // the important part
    for (const auto &e : tempLog) outFile << e << "\n";

}

void Simulation::run(int iterations) {
    for (int i = 0; i < iterations; i++) {
        iteration();
    }
}

void Simulation::setRegulator(bool isBB) {
    if (isBB){
        RegulatorBB* regPtr = new RegulatorBB(this->setTemp_, &(this->room),&(this->heater));
        this->regulator.push_back(regPtr);
    }
    else{
        PID* regPtr = new PID(setTemp_, &(this->room),&(this->heater),0.2,0.002,0);
        this->regulator.push_back(regPtr);
    }
}
Simulation::Simulation(float dtime,float heaterMaxPower,float height,float width,float deep,float setTemp,bool isBB)
        : dt(dtime), room(height,width,deep),heater(heaterMaxPower),setTemp_(setTemp){
    setRegulator(isBB);
}