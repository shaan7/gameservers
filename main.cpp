#include "qtquick2controlsapplicationviewer.h"

#include "serversmodel.h"

#include <QUdpSocket>
#include <QtQml/QQmlEngine>
#include <qqml.h>

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    qmlRegisterType<ServersModel>("com.thoughtworks.gameservers", 1, 0, "ServersModel");

    QtQuick2ControlsApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/gameservers/main.qml"));
    viewer.show();

    return app.exec();
}
