#include "pinger.h"

#include <QUrl>

namespace {
    char peer0_0[] = {
        0xff, 0xff, 0xff, 0xff,
        0x54, 0x53, 0x6f, 0x75,
        0x72, 0x63, 0x65, 0x20,
        0x45, 0x6e, 0x67, 0x69,
        0x6e, 0x65, 0x20, 0x51,
        0x75, 0x65, 0x72, 0x79, 0x00
    };
}

Pinger::Pinger(QObject *parent) :
    QObject(parent)
{
    connect(&m_socket, &QUdpSocket::readyRead, this, &Pinger::readDataFromSocket);
}

void Pinger::ping(const QString &host, quint16 port)
{
    m_socket.close();
    m_socket.connectToHost(QHostAddress(host), port);
    m_socket.write(peer0_0);

    m_pingStartTime = QTime::currentTime();
}

void Pinger::readDataFromSocket()
{
    m_lastLatency = QTime::currentTime().msec() - m_pingStartTime.msec();
    Q_EMIT latencyChanged();
}

int Pinger::latency() const
{
    return m_lastLatency;
}
