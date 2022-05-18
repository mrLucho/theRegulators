#include <iostream>
#include <limits>
#include "simulation.h"
int main() {
//    Simulation sim = Simulation(0.1,3000,1,1,1,30, true);
//    sim.run(100);

    float safeFloatInputGreaterThan0(std::string paramName);
    int safeIntInputGreaterThan0(std::string paramName);


    std::cout<<"Welcome in automatic regulation sim, enter here parameters "<<std::endl;

    std::cout<<"Room"<<std::endl;
    float height = safeFloatInputGreaterThan0("height");
    float width = safeFloatInputGreaterThan0("width");
    float deep = safeFloatInputGreaterThan0("depth");

    std::cout<<"Heater"<<std::endl;
    float maxPower = safeFloatInputGreaterThan0("heater max power");

    std::cout<<"time"<<std::endl;
    float dt = safeFloatInputGreaterThan0("time");

    float setTemp;
    for (;;) {
        std::cout << "Please enter in temp to be set "<<": ";
        if (std::cin >> setTemp and setTemp >-273) {
            break;
        } else {
            std::cout << "Please enter a valid temperature"<<":"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::string regType;
    bool isBB;

    for (;;) {
        std::cout << "Please enter regulator_ type BB or PID "<<": ";
        if (std::cin >> regType and (regType == "BB" or regType == "PID") ) {
            if (regType =="BB") { isBB = true; }
            else { isBB = false; }
            break;
        } else {
            std::cout << "Please enter a type"<<":"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

//    all params set
    Simulation sim = Simulation(dt,maxPower,height,width,deep,setTemp,isBB);
    sim.run(safeIntInputGreaterThan0("iterations"));



    return 0;
}


float safeFloatInputGreaterThan0(std::string paramName) {
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

int safeIntInputGreaterThan0(std::string paramName) {
    int num;
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
