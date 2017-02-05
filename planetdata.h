#ifndef PLANETDATA_H
#define PLANETDATA_H

#include <QVector2D>

struct PlanetData
{
public:
    PlanetData(QVector2D position, QVector2D speed, float mass);
    PlanetData advance(QVector2D acceleration, float time) const;

public:
    const QVector2D position;
    const QVector2D speed;
    const float mass;
};

#endif // PLANETDATA_H
