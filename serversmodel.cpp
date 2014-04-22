#include "serversmodel.h"

#include "pinger.h"

ServersModel::ServersModel(QObject *parent) :
    QAbstractListModel(parent)
{
    initServerList();
}

QHash<int, QByteArray> ServersModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles.insert(HostRole, "host");
    roles.insert(PortRole, "port");
    roles.insert(PingRole, "ping");

    return roles;
}

void ServersModel::initServerList()
{
    mServerList << "89.44.246.192:27015"
                << "89.44.246.19:27015"
                << "77.220.180.75:27015"
                << "94.23.76.127:27015"
                << "89.44.246.236:27015"
                << "80.77.174.155:27016"
                << "93.119.24.206:27015"
                << "176.57.142.99:27042"
                << "89.44.246.127:27015"
                << "89.44.246.35:27015"
                << "193.84.64.118:27015"
                << "193.26.217.101:27048"
                << "109.202.33.58:27015"
                << "193.192.59.74:27099"
                << "89.44.246.213:27015";
}

int ServersModel::rowCount(const QModelIndex &parent) const
{
    return mServerList.size();
}

QVariant ServersModel::data(const QModelIndex &index, int role) const
{
    const int row = index.row();
    const auto server = mServerList.at(row);

    switch (role) {
    case HostRole:
        return server.split(':').first();
    case PortRole:
        return server.split(':').last();
    case PingRole:
        if (!mLastKnownPing.contains(server)) {
            const_cast<ServersModel*>(this)->createPinger(server);
            return QVariant();
        }
        return mLastKnownPing.value(server);
    }

    return QVariant();
}

void ServersModel::createPinger(const QString &server)
{
    ServersModel *m = const_cast<ServersModel*>(this);
    Pinger *p = new Pinger(QHostAddress(server.split(':').first()), server.split(':').last().toUInt(), m);
    connect(p, SIGNAL(latencyChanged()), SLOT(latency()));

    p->initiatePing();

    mPingers.insert(p, server);
}

void ServersModel::latency()
{
    Pinger *p = static_cast<Pinger*>(sender());

    auto server = mPingers.value(p);
    mLastKnownPing.insert(server, p->latency());

    int pos = mServerList.indexOf(server);
    Q_EMIT dataChanged(index(pos), index(pos));
}
