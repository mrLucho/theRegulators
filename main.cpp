#include <iostream>
#include "simulation.h"
int main() {
    Simulation sim = Simulation(0.1,300,1,1,1,20);
    sim.run(100);
    sim.save2file("results.txt");
    return 0;
}
