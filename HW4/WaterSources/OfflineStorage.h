//
// Created by bernardo on 6/12/18.
//

#ifndef CPPTRAINING_QUARRY_H
#define CPPTRAINING_QUARRY_H

#include "StorageInfrastructure.h"

class OfflineStorage : public StorageInfrastructure {

public:
    OfflineStorage(const string &name, const double capacity, double min_env_flow, double max_diversion, int simulation_time);

    double max_diversion = -1;

    OfflineStorage(const OfflineStorage &reservoir);

    virtual ~OfflineStorage();

    double performMassBalance(double upstream_flow, int week) override;
};


#endif //CPPTRAINING_QUARRY_H
