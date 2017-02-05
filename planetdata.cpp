#include "planetdata.h"

PlanetData::PlanetData(QVector2D p, QVector2D s, float m) : position(p), speed(s), mass(m)
{
}

PlanetData PlanetData::advance(QVector2D acceleration, float time) const
{
    QVector2D newPos = position + time*speed;
    QVector2D newSpeed = speed + time*acceleration;
    return PlanetData(newPos, newSpeed, mass);
}
