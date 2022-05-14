//
// Created by user on 12.05.2022.
//

#include "simulation.h"

//
void Simulation::iteration(float dt) {

}

void Simulation::save2file(std::string filename) {

}

void Simulation::run(int iterations, float dt) {

}

void Simulation::setRegulator(bool isBB) {
    if (isBB){
        RegulatorBB* regulatorBb = new RegulatorBB();
        Regulator* ptr = dynamic_cast<Regulator*>(regulatorPtr);
        this->regulatorPtr = ptr;
    }
}
