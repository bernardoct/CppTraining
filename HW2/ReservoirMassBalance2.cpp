#include <iostream>
#include <random>
#include <vector>

using namespace std;

void initializeVectors(vector<vector<double>> &catchment_inflows, vector<vector<double>> &evaporations,
                       const double max_inflow, const double min_inflow, const int number_of_time_steps) {

    unsigned long number_of_reservoirs = evaporations.size();

    // Populate inflows and evaporation vectors with random values, volumes with capacities, and min env flows.
    for (int r = 0; r < number_of_reservoirs; ++r) {
        for (int t = 0; t < number_of_time_steps; ++t) {
            catchment_inflows[r].push_back(1. * rand() / RAND_MAX * max_inflow);
            evaporations[r].push_back(1. * rand() / RAND_MAX * max_inflow);
        }
    }
}

double performMassBalance(double &volume, const double upstream_release, const double catchment_inflow,
                          const double evaporation, const double min_env_flow, const double capacity) {
    double release;

    volume += upstream_release + catchment_inflow - evaporation - min_env_flow;
    if (volume > capacity) {
        release += volume - capacity;
        volume = capacity;
    } else if (volume < 0.) {
        release = min_env_flow + volume;
        volume = 0.;
    } else {
        release = min_env_flow;
    }

    return release;
}

int main() {
    // Define constants
    const int NUMBER_OF_RESERVOIRS = 3;
    const int NUMBER_OF_TIME_STEPS = 25;
    const double CAPACITY = 100.;
    const double MIN_ENV_FLOW = 5.;
    const double MAX_INFLOWS_EVAP = 10.;
    const double MIN_INFLOWS_EVAP = 0.;

    // Declare state and time series variables
    vector<double> volumes(NUMBER_OF_RESERVOIRS, CAPACITY);
    vector<double> min_env_flows(NUMBER_OF_RESERVOIRS, MIN_ENV_FLOW);
    vector<vector<double>> catchment_inflows(NUMBER_OF_RESERVOIRS);
    vector<vector<double>> evaporations(NUMBER_OF_RESERVOIRS);

    // Populate inflows and evaporation vectors with random values, volumes with capacities, and min env flows.
    initializeVectors(catchment_inflows, evaporations, MAX_INFLOWS_EVAP, MIN_INFLOWS_EVAP, NUMBER_OF_TIME_STEPS);

    // Time loop
    for (int t = 0; t < NUMBER_OF_TIME_STEPS; ++t) {
        std::cout << "Week " << t << ": ";
        double upstream_release = 0.;

        // Reservoir loop
        for (int r = 0; r < NUMBER_OF_RESERVOIRS; ++r) {

            // Perform mass balance
            upstream_release = performMassBalance(volumes[r], upstream_release, catchment_inflows[r][t],
                                                  evaporations[r][t], min_env_flows[r], CAPACITY);
            std::cout << volumes[r] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}