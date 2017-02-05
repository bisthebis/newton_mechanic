#ifndef SIMULATIONSTEP_H
#define SIMULATIONSTEP_H

#include "planetdata.h"

struct SimulationStep
{
public:
    SimulationStep() = default;
    SimulationStep(PlanetData A, PlanetData B);
    SimulationStep advance(float G, float time);
    SimulationStep(const SimulationStep& src) = default;

    PlanetData A;
    PlanetData B;
};

#endif // SIMULATIONSTEP_H
