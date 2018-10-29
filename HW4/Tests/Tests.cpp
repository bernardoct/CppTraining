//
// Created by bernardo on 10/29/18.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../WaterSources/Reservoir.h"
#include "../WaterSources/OfflineStorage.h"

TEST_CASE("Mass balance reservoir", "[Reservoir][Mass Balance]") {
    const double CAPACITY = 100.;
    const double MIN_ENV_FLOW = 5.;
    const int NUMBER_OF_TIME_STEPS = 25;

    Reservoir nice_lake("nice", CAPACITY, MIN_ENV_FLOW, NUMBER_OF_TIME_STEPS);

    SECTION("Overflow") {
        double upstream_release = 300.;
        int t = 1;

        double release = nice_lake.performMassBalance(upstream_release, t);
        double stored_volume_new = nice_lake.getStored_volume()[t];
        double catchment_inflows = nice_lake.getCatchment_inflows()[t];
        double evaporation = nice_lake.getEvaporations()[t];

        REQUIRE(CAPACITY - stored_volume_new + upstream_release + catchment_inflows - evaporation - release == 0);
    }
}

TEST_CASE("Mass balance offline storage", "[OfflineStorage][Mass Balance]") {
    const double CAPACITY = 100.;
    const double MIN_ENV_FLOW = 5.;
    const int NUMBER_OF_TIME_STEPS = 25;
    const double max_diversion = 2.;

    SECTION("With random inflows/evaporations") {
        double upstream_release = 300.;
        int t = 1;

        OfflineStorage quarry("quarry", CAPACITY, MIN_ENV_FLOW, max_diversion, NUMBER_OF_TIME_STEPS);

        double release = quarry.performMassBalance(upstream_release, t);
        double stored_volume_new = quarry.getStored_volume()[t];
        double catchment_inflows = quarry.getCatchment_inflows()[t];
        double evaporation = quarry.getEvaporations()[t];

        REQUIRE(CAPACITY - stored_volume_new + upstream_release + catchment_inflows - evaporation - release == 0);
    }

    SECTION("Under Capacity") {
        double upstream_release = 0.;
        double stored_volume_t0 = 50.;
        int t = 1;

        OfflineStorage quarry("quarry", CAPACITY, MIN_ENV_FLOW, max_diversion, NUMBER_OF_TIME_STEPS);

        double* evap = new double[2];
        evap[0] = 10.;
        evap[1] = 10.;
        quarry.setEvaporations(evap);
        double* inflows = new double[2];
        inflows[0] = 10.;
        inflows[1] = 10.;
        quarry.setCatchment_inflows(inflows);

        quarry.setStored_volume(vector<double>(1, stored_volume_t0));

        double release = quarry.performMassBalance(upstream_release, t);
        double stored_volume_new = quarry.getStored_volume()[t];
        double catchment_inflows = quarry.getCatchment_inflows()[t];
        double evaporation = quarry.getEvaporations()[t];

        REQUIRE(stored_volume_t0 - stored_volume_new + upstream_release + catchment_inflows - evaporation - release == 0);
    }
}