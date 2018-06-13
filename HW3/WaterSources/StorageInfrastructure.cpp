//
// Created by bernardo on 6/12/18.
//

#include "StorageInfrastructure.h"

StorageInfrastructure::StorageInfrastructure(const string &name, const double capacity, double min_env_flow,
                                             int simulated_time)
        : name(name), capacity(capacity), min_env_flow(min_env_flow) {

    evaporations = new double[simulated_time];
    catchment_inflows = new double[simulated_time];

    for (int t = 0; t < simulated_time; ++t) {
        catchment_inflows[t] = 1. * rand() / RAND_MAX * MAX_INFLOW_EVAP;
        evaporations[t] = 1. * rand() / RAND_MAX * MAX_INFLOW_EVAP;
    }

}

const vector<double> &StorageInfrastructure::getStored_volume() const {
    return stored_volume;
}


