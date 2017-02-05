#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "simulation.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Simulation>("Planet.Simulation", 1, 0, "Simulation");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
