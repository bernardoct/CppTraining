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

    std::cout << "Week\t";
    for (Reservoir &r : reservoirs_simulation1) {
        printf("Stored vol. %s\tCatchment Inflows %s\tEvaporations %s\tRelease %s\t", r.name.c_str(), r.name.c_str(), r.name.c_str(), r.name.c_str());
    }
    std::cout << std::endl;

    for (int t = 1; t < NUMBER_OF_TIME_STEPS; ++t) {
        double upstream_release = 0.;
        std::cout << t << "\t";

        // Reservoir loop
        for (Reservoir &r : reservoirs_simulation1) {

            // Perform mass balance
            upstream_release = r.performMassBalance(upstream_release, t);
            std::cout << r.getStored_volume()[t] << "\t";
            std::cout << r.getCatchment_inflows()[t] << "\t";
            std::cout << r.getEvaporations()[t] << "\t";
            std::cout << upstream_release << "\t";
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