#ifndef PINGER_H
#define PINGER_H

#include <QObject>
#include <QUdpSocket>
#include <QTime>

class Pinger : public QObject
{
    Q_OBJECT
public:
    explicit Pinger(const QHostAddress &host, quint16 port, QObject *parent = 0);
    int latency() const;

public Q_SLOTS:
    void initiatePing();

private Q_SLOTS:
    void readDataFromSocket();

Q_SIGNALS:
    void latencyChanged();

private:
    QHostAddress m_host;
    quint16 m_port;
    QUdpSocket m_socket;
    QTime m_pingStartTime;
    int m_lastLatency = 0;

    void reconnect();
};

#endif // PINGER_H
