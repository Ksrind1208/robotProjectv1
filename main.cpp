#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "backend.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/projectRobot1/Main.qml"));

    qmlRegisterType<Backend>("Data",1,0,"Backend");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
