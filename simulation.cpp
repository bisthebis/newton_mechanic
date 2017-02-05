#include "simulation.h"
#include <QDebug>
Simulation::Simulation(QObject *parent) : QObject(parent)
{

}

void Simulation::initialize(SimulationStep init, float G, float p)
{
    steps.clear();
    steps.append(init);
    emit a_moved();
    emit b_moved();
    this->G = G;
    this->period = p;
}

void Simulation::defaultInit() {
    auto Earth = PlanetData({900,500}, {0,0}, 100);
    auto Moon = PlanetData({800, 250}, {-0.3,0}, 1);
    initialize(SimulationStep(Earth, Moon), 0.5, 5);
}

QVector2D Simulation::a_pos() const {
    return steps.last().A.position;
}
QVector2D Simulation::b_pos() const {
    return steps.last().B.position;
}

void Simulation::advance() {
    steps.append(steps.last().advance(G, period));
    emit a_moved();
    emit b_moved();
}

float Simulation::xa() const {
    return a_pos().x();
}
float Simulation::ya() const {
    return a_pos().y();
}
float Simulation::xb() const {
    return b_pos().x();
}
float Simulation::yb() const {
    return b_pos().y();
}
float Simulation::ma() const {
    return steps.last().A.mass;
}
float Simulation::mb() const {
    return steps.last().B.mass;
}
