#include <iostream>
#include "simulation.h"
int main() {
    Simulation sim = Simulation(1,300,1,1,1);
//    sim.heater.works();
//    sim.setRegulator(true);
    sim.run(1,100);

//    sim.heater.works();
    return 0;
}
