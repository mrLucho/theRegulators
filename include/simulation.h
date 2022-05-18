#ifndef THEREGULATORS_SIMULATION_H
#define THEREGULATORS_SIMULATION_H

#include <cstdio>
#include <vector>
#include <string>

#include "PIDregulator.h"
#include "regulatorBB.h"

struct TooLowTemp : public std::exception{
    const char * what () const throw (){
        return "temperature exceeded Absolute 0";
    }
};

struct NoRegulatorPresent : public std::exception{
    const char * what () const throw (){
        return "roomPtr is null or nullptr";
    }
};

// main class, lots of inputs here to avoid it later
class Simulation{
public:
    Simulation(float dtime,float heaterMaxPower,float height,float width,float deep,float setTemp = 20,bool isBB = true);
    void setRegulator(bool isBB);

    void iteration();
    void save2file(const std::string& filename);
    void run(int iterations=10);

    Heater heater;
    Pomieszczenie room;
    ~Simulation(){delete regulator_[0];}


private:
    const float dt_; //float to be compatible with pomieszczenie class
    std::vector<float> tempLog_;
    static float safeFloatInputGreaterThan0(std::string paramName) ;

    std::vector<Regulator*>regulator_;
    float setTemp_;
    float currentTime_= 0;
};
#endif //THEREGULATORS_SIMULATION_H
