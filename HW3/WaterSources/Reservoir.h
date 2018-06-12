//
// Created by bernardo on 6/12/18.
//

#ifndef CPPTRAINING_RESERVOIR_H
#define CPPTRAINING_RESERVOIR_H


#include "StorageInfrastructure.h"

class Reservoir : public StorageInfrastructure {

public:
    Reservoir(const string &name, const double capacity, double min_env_flow, int simulation_time);

    double performMassBalance(double upstream_flow, int week) override;

    virtual ~Reservoir();
};


#endif //CPPTRAINING_RESERVOIR_H
