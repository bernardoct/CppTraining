//
// Created by bernardo on 6/12/18.
//

#include <random>
#include <iostream>
#include "WaterSources/Reservoir.h"

int main() {
    const double CAPACITY = 100.;
    const double MIN_ENV_FLOW = 5.;
    const int NUMBER_OF_TIME_STEPS = 25;

    Reservoir nice_lake("nice", 100., MIN_ENV_FLOW, NUMBER_OF_TIME_STEPS);
    Reservoir gross_lake("gross", 100., MIN_ENV_FLOW, NUMBER_OF_TIME_STEPS);
    Reservoir ok_lake("ok", 100., MIN_ENV_FLOW, NUMBER_OF_TIME_STEPS);

    vector<Reservoir> reservoirs_simulation1 = {nice_lake, gross_lake, ok_lake};
    vector<Reservoir> reservoirs_simulation2 = {nice_lake, gross_lake, ok_lake};

    for (int t = 1; t < NUMBER_OF_TIME_STEPS; ++t) {
        double upstream_release = 0.;
        std::cout << "Week " << t << ": ";

        // Reservoir loop
        for (Reservoir &r : reservoirs_simulation1) {

            // Perform mass balance
            upstream_release = r.performMassBalance(upstream_release, t);
//            std::cout << r.getStored_volume()[t] << " ";
            std::cout << upstream_release << " ";
        }
        std::cout << std::endl;
    }

//    for (int t = 1; t < NUMBER_OF_TIME_STEPS; ++t) {
//        double upstream_release = 0.;
//        std::cout << "Week " << t << ": ";
//
//        // Reservoir loop
//        for (Reservoir &r : reservoirs_simulation2) {
//
//            // Perform mass balance
//            upstream_release = r.performMassBalance(upstream_release, t);
//            std::cout << r.getStored_volume()[t] << " ";
//        }
//        std::cout << std::endl;
//    }

}