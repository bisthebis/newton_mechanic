#include "simulationstep.h"

SimulationStep::SimulationStep(PlanetData a, PlanetData b) : A(a), B(b)
{

}
SimulationStep SimulationStep::advance(float G, float time)
{
    float distanceSquared = (A.position - B.position).lengthSquared();
    float forceMag = G * A.mass * B.mass / distanceSquared;
    auto accelerationA = (B.position - A.position).normalized() * forceMag / A.mass;
    auto accelerationB = (A.position - B.position).normalized() * forceMag / B.mass;

    auto newA = A.advance(accelerationA, time);
    auto newB = B.advance(accelerationB, time);

    return SimulationStep(newA, newB);
}
