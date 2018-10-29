//
// Created by bernardo on 6/12/18.
//

#ifndef CPPTRAINING_WATERSOURCE_H
#define CPPTRAINING_WATERSOURCE_H

#include <string>
#include <vector>
#include <random>

using namespace std;

class StorageInfrastructure {

    const double MIN_INFLOW_EVAP = 0.;
    const double MAX_INFLOW_EVAP = 10.;
    int simulated_time;
public:
    const string name;
    const double capacity;
protected:
    double* catchment_inflows;
    double* evaporations;
    vector<double> stored_volume;
    double min_env_flow;

    // Create uniform distribution for inflow and evaporation sampling
    std::uniform_real_distribution<double> unif;

public:
    StorageInfrastructure(const string &name, const double capacity, double min_env_flow,
                              int simulated_time);

    StorageInfrastructure(const StorageInfrastructure &storage_infrastructure);

    StorageInfrastructure& operator=(const StorageInfrastructure& storageInfrastructure);

    ~StorageInfrastructure();

    void generateEvaporationsInflows(double* evaporations, double* catchment_inflows);

    virtual double performMassBalance(double upstream_flow, int week) = 0;

    const vector<double> &getStored_volume() const;

    void
    copyEvaporationsInflows(double *evaporations, double *catchment_inflows, const StorageInfrastructure &storageInfrastructure);

    double *getCatchment_inflows() const;

    double *getEvaporations() const;

    void setCatchment_inflows(double *catchment_inflows);

    void setEvaporations(double *evaporations);

    void setStored_volume(const vector<double> &stored_volume);
};


#endif //CPPTRAINING_WATERSOURCE_H
