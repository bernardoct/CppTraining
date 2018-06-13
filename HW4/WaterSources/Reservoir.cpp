//
// Created by bernardo on 6/12/18.
//

#include "Reservoir.h"

Reservoir::Reservoir(const string &name, const double capacity, double min_env_flow, int simulation_time)
        : StorageInfrastructure(name, capacity, min_env_flow, simulation_time) {
    stored_volume.push_back(capacity);
}

Reservoir::Reservoir(const Reservoir& reservoir) = default;

Reservoir::~Reservoir() = default;

/**
 * Performs mass balance calculations for reservoir.
 * @param upstream_flow flow released by upstream storage infrastructure (excluding gains from reservoir's catchment).
 * @param week
 * @return the release.
 */
double Reservoir::performMassBalance(double upstream_flow, int week) {
    double new_stored_volume = stored_volume[week - 1] + upstream_flow + catchment_inflows[week] -
            evaporations[week] - min_env_flow;
    double release = min_env_flow;

    if (new_stored_volume > capacity) {
        release += new_stored_volume - capacity;
        new_stored_volume = capacity;
    } else if (new_stored_volume < 0.) {
        release = max(min_env_flow + new_stored_volume, 0.);
        new_stored_volume = 0.;
    } else {
        release = min_env_flow;
    }

    stored_volume.push_back(new_stored_volume);
    return release;
}
