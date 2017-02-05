#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QVector>
#include "simulationstep.h"

class Simulation : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVector2D a_pos READ a_pos NOTIFY a_moved)
    Q_PROPERTY(QVector2D b_pos READ b_pos NOTIFY b_moved)
    Q_PROPERTY(float xa READ xa)
    Q_PROPERTY(float ya READ ya)
    Q_PROPERTY(float xb READ xb)
    Q_PROPERTY(float yb READ yb)
    Q_PROPERTY(float ma READ ma)
    Q_PROPERTY(float mb READ mb)
public:
    explicit Simulation(QObject *parent = 0);

signals:
    void a_moved();
    void b_moved();

public slots:
    void initialize(SimulationStep init, float G, float p);
    void defaultInit();
    void advance();
    QVector2D a_pos() const;
    QVector2D b_pos() const;
    float xa() const;
    float ya() const;
    float xb() const;
    float yb() const;
    float ma() const;
    float mb() const;
private:
    QVector<SimulationStep> steps;
    float G = 0.01;
    float period = 1;
};

#endif // SIMULATION_H
