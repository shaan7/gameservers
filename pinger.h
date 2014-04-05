#ifndef PINGER_H
#define PINGER_H

#include <QObject>
#include <QUdpSocket>
#include <QTime>

class Pinger : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int latency READ latency NOTIFY latencyChanged)
public:
    explicit Pinger(QObject *parent = 0);
    int latency() const;

public Q_SLOTS:
    void ping(const QString &host, quint16 port);

private Q_SLOTS:
    void readDataFromSocket();

Q_SIGNALS:
    void latencyChanged();

private:
    QUdpSocket m_socket;
    QTime m_pingStartTime;
    int m_lastLatency = 0;
};

#endif // PINGER_H
