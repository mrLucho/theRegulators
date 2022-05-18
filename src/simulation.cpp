#include <iostream>
#include "simulation.h"
#include <vector>
#include <fstream>
#include <limits>


void Simulation::iteration() {
    float temp;
    if (regulator_.empty() or regulator_[0] == nullptr) throw NoRegulatorPresent();
    try {
          temp= (regulator_[0])->control(dt_);
    }
    catch (NoRegulatorPresent& noRegulatorPresent) {
        std::cout<<noRegulatorPresent.what()<<std::endl;
    }

    if (temp < -273.15) throw TooLowTemp();
    save2file("results.csv");

//    temp log not used much
    tempLog_.push_back(temp);
    currentTime_+=dt_;
    std::cout<<temp<<std::endl;
}

void Simulation::save2file(const std::string& filename) {
    std::ofstream outFile(filename,std::ios::app);
    // the important part
    outFile << room.getTemperatura() << "," << heater.getCurrentPower() << "," << currentTime_ << std::endl;


}

void Simulation::run(int iterations) {
    for (int i = 0; i < iterations; i++) {
        iteration();
    }
}

void Simulation::setRegulator(bool isBB) {
    if (isBB){
        RegulatorBB* regPtr = new RegulatorBB(this->setTemp_, &(this->room),&(this->heater));
        this->regulator_.push_back(regPtr);
    }
    else{
        float kp= safeFloatInputGreaterThan0("kp");
        float ki= safeFloatInputGreaterThan0("ki");
        float kd= safeFloatInputGreaterThan0("kd");

        PID* regPtr = new PID(setTemp_, &(this->room),&(this->heater),kp,ki,kd);
        this->regulator_.push_back(regPtr);
    }
}
Simulation::Simulation(float dtime,float heaterMaxPower,float height,float width,float deep,float setTemp,bool isBB)
        : dt_(dtime), room(height, width, deep), heater(heaterMaxPower), setTemp_(setTemp){
    setRegulator(isBB);
    std::ofstream ofs;
    ofs.open("results.csv", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}


float Simulation::safeFloatInputGreaterThan0(std::string paramName) {
    float num;
    for (;;) {
        std::cout << "Please enter in "<<paramName<<": ";
        if (std::cin >> num and num >0) {
            return num;
        } else {
            std::cout << "Please enter a valid "<<paramName <<":"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

