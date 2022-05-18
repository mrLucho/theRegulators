#include <iostream>
#include "simulation.h"
int main() {
//    todo: make a menu with all checked inputs for this constr and provide same styling for Simulation::setRegulator in case of pid
    Simulation sim = Simulation(0.1,3000,1,1,1,30, false);
    sim.run(100);
    return 0;
}
