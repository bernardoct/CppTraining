#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
    // Define constants
    const int NUMBER_OF_RESERVOIRS = 3;
    const int NUMBER_OF_TIME_STEPS = 25;
    const double CAPACITY = 100.;
    const double MIN_ENV_FLOW = 5.;
    const double MAX_INFLOW_EVAP = 10.;
    const double MIN_INFLOW_EVAP = 0.;

    // Declare state and time series variables
    double volumes[NUMBER_OF_RESERVOIRS];
    double min_env_flows[NUMBER_OF_RESERVOIRS];
    double catchment_inflows[NUMBER_OF_RESERVOIRS][NUMBER_OF_TIME_STEPS];
    double evaporations[NUMBER_OF_RESERVOIRS][NUMBER_OF_TIME_STEPS];

    // Populate inflows and evaporation vectors with random values, volumes with capacities, and min env flows.
    for (int r = 0; r < NUMBER_OF_RESERVOIRS; ++r) {
        for (int t = 0; t < NUMBER_OF_TIME_STEPS; ++t) {
            catchment_inflows[r][t] = 1. * rand() / RAND_MAX * MAX_INFLOW_EVAP;
            evaporations[r][t] = 1. * rand() / RAND_MAX * MAX_INFLOW_EVAP;
        }
        volumes[r] = CAPACITY;
        min_env_flows[r] = MIN_ENV_FLOW;
    }

    // Time loop
    for (int t = 0; t < NUMBER_OF_TIME_STEPS; ++t) {
        std::cout << "Week " << t << ": ";
        double release = 0.;

        // Reservoir loop
        for (int r = 0; r < NUMBER_OF_RESERVOIRS; ++r) {

            // Perform mass balance
            volumes[r] += release + catchment_inflows[r][t] - evaporations[r][t] - min_env_flows[r];
            double upstream_release = release;
            release = min_env_flows[r];
            if (volumes[r] > CAPACITY) {
                release += volumes[r] - CAPACITY;
                volumes[r] = CAPACITY;
            } else if (volumes[r] < 0) {
                release = max(min_env_flows[r] + volumes[r], 0.);
                volumes[r] = 0;
            } else {
                release = min_env_flows[r];
            }
            std::cout << volumes[r] << " " << upstream_release << " " << catchment_inflows[r][t] << " "
                      << evaporations[r][t] << " " << release << "         ";
        }
        std::cout << std::endl;
    }

    return 0;
}