//
// Created by bernardo on 6/12/18.
//

#include "OfflineStorage.h"

OfflineStorage::OfflineStorage(const string &name, const double capacity, double min_env_flow, double max_diversion,
                               int simulation_time) : StorageInfrastructure(name, capacity, min_env_flow,
                                       simulation_time), max_diversion(max_diversion)  {
    stored_volume.push_back(capacity);
}

OfflineStorage::OfflineStorage(const OfflineStorage& offline_storage) = default;

OfflineStorage::~OfflineStorage() = default;

double OfflineStorage::performMassBalance(double upstream_flow, int week) {
    double new_stored_volume = stored_volume[week - 1] + min(upstream_flow + catchment_inflows[week] -
                               evaporations[week] - min_env_flow, max_diversion);
    double non_diverted_flow = min_env_flow + max(0., upstream_flow + catchment_inflows[week] -
                                                      evaporations[week] - min_env_flow - max_diversion);

    if (new_stored_volume > capacity) {
        non_diverted_flow += new_stored_volume - capacity;
        new_stored_volume = capacity;
    } else if (new_stored_volume < 0.) {
        non_diverted_flow = max(min_env_flow + new_stored_volume, 0.);
        new_stored_volume = 0.;
    }

    stored_volume.push_back(new_stored_volume);
    return non_diverted_flow;
}