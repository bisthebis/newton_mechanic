#ifndef SIMULATIONSTEP_H
#define SIMULATIONSTEP_H

#include "planetdata.h"

struct SimulationStep
{
public:
    SimulationStep(PlanetData A, PlanetData B);
    SimulationStep advance(float G, float time);

    PlanetData A;
    PlanetData B;
};

#endif // SIMULATIONSTEP_H
