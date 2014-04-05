#include "qtquick2controlsapplicationviewer.h"

#include "pinger.h"

#include <QUdpSocket>
#include <QtQml/QQmlEngine>
#include <qqml.h>

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    qmlRegisterType<Pinger>("com.thoughtworks.gameservers", 1, 0, "Pinger");
    QtQuick2ControlsApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/gameservers/main.qml"));
    viewer.show();

    return app.exec();
}
