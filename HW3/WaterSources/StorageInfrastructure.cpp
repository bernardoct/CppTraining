//
// Created by bernardo on 6/12/18.
//

#include "StorageInfrastructure.h"

StorageInfrastructure::StorageInfrastructure(const string &name, const double capacity, double min_env_flow,
                                             int simulated_time)
        : name(name), capacity(capacity), min_env_flow(min_env_flow) {

    unif = std::uniform_real_distribution<double>(MIN_INFLOW_EVAP, MAX_INFLOW_EVAP);

    evaporations = new double[simulated_time];
    catchment_inflows = new double[simulated_time];

    for (int t = 0; t < simulated_time; ++t) {
        evaporations[t] = unif(re);
        catchment_inflows[t] = unif(re);
    }

}

const vector<double> &StorageInfrastructure::getStored_volume() const {
    return stored_volume;
}


