//
// Created by user on 12.05.2022.
//

#include <iostream>
#include "simulation.h"
#include <vector>
#include <fstream>
#include <limits>

//
void Simulation::iteration() {
    float temp;
    if (regulator.empty() or regulator[0] == nullptr) throw NoRegulatorPresent();
    try {
          temp= (regulator[0])->control(dt_);
    }
    catch (NoRegulatorPresent& noRegulatorPresent) {
        std::cout<<noRegulatorPresent.what()<<std::endl;
    }

    if (temp < -273.15) throw TooLowTemp();
    save2file("results.csv");

    tempLog.push_back(temp);
    currentTime+=dt_;
    std::cout<<temp<<std::endl;
}

void Simulation::save2file(const std::string& filename) {
    std::ofstream outFile(filename,std::ios::app);
    // the important part
    outFile << room.getTemperatura() << ","<< heater.getCurrentPower() << "," << currentTime<<std::endl;


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
        /*
         * todo: ask for params for pid
         */
        PID* regPtr = new PID(setTemp_, &(this->room),&(this->heater),0.2,0.02,0.02);
        this->regulator.push_back(regPtr);
    }
}
Simulation::Simulation(float dtime,float heaterMaxPower,float height,float width,float deep,float setTemp,bool isBB)
        : dt_(dtime), room(height, width, deep), heater(heaterMaxPower), setTemp_(setTemp){
    setRegulator(isBB);
    std::ofstream ofs;
    ofs.open("results.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

