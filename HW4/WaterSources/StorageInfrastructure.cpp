//
// Created by bernardo on 6/12/18.
//

#include <cstring>
#include "StorageInfrastructure.h"

StorageInfrastructure::StorageInfrastructure(const string &name, const double capacity, double min_env_flow,
                                             int simulated_time)
        : name(name), capacity(capacity), min_env_flow(min_env_flow), simulated_time(simulated_time) {

    // Create new time series.
    evaporations = new double[simulated_time];
    catchment_inflows = new double[simulated_time];

    // Create new random time series.
    generateEvaporationsInflows(evaporations, catchment_inflows);
}

StorageInfrastructure::StorageInfrastructure(const StorageInfrastructure& storage_infrastructure) :
        name(storage_infrastructure.name), capacity(storage_infrastructure.capacity),
        simulated_time(storage_infrastructure.simulated_time), stored_volume(storage_infrastructure.stored_volume),
        min_env_flow(storage_infrastructure.min_env_flow) {
    // Create time series.
    evaporations = new double[simulated_time];
    catchment_inflows = new double[simulated_time];

    // Copy time series
    copyEvaporationsInflows(evaporations, catchment_inflows, storage_infrastructure);

//    // Create new random time series.
//    generateEvaporationsInflows(evaporations, catchment_inflows);
}

StorageInfrastructure& StorageInfrastructure::operator=(const StorageInfrastructure& storage_infrastructure) {
    simulated_time = storage_infrastructure.simulated_time;
    stored_volume = storage_infrastructure.stored_volume;
    min_env_flow = storage_infrastructure.min_env_flow;

    // Create time series.
    evaporations = new double[simulated_time];
    catchment_inflows = new double[simulated_time];

    // Copy time series
    copyEvaporationsInflows(evaporations, catchment_inflows, storage_infrastructure);

//    // Create new random time series
//    generateEvaporationsInflows(evaporations, catchment_inflows);

    return *this;
}

StorageInfrastructure::~StorageInfrastructure() {
    delete[] evaporations;
    delete[] catchment_inflows;
}

void StorageInfrastructure::copyEvaporationsInflows(double *evaporations, double *catchment_inflows,
                                                    const StorageInfrastructure& storage_infrastructure) {
    // Copy time series from original objects to new objects.
    memcpy(evaporations, storage_infrastructure.evaporations,
           sizeof(double) * simulated_time);
    memcpy(catchment_inflows, storage_infrastructure.catchment_inflows,
           sizeof(double) * simulated_time);
}

void StorageInfrastructure::generateEvaporationsInflows(double *evaporations, double *catchment_inflows) {
    std::default_random_engine re;

    // Generate random inflows and evaporations. I know, this is not log-normal but let's keep it simple.
    for (int t = 0; t < simulated_time; ++t) {
        evaporations[t] = 1. * rand() / RAND_MAX * MAX_INFLOW_EVAP;
        catchment_inflows[t] = 1. * rand() / RAND_MAX * MAX_INFLOW_EVAP;
    }
}

const vector<double> &StorageInfrastructure::getStored_volume() const {
    return stored_volume;
}


