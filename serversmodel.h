#ifndef SERVERSMODEL_H
#define SERVERSMODEL_H

#include <QAbstractListModel>

class Pinger;

class ServersModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ServerRoles { HostRole, PortRole, PingRole };
    explicit ServersModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

signals:

private slots:
    void latency();

private:
    QStringList mServerList;
    QHash<QString, int> mLastKnownPing;
    QHash<Pinger*, QString> mPingers;

    void initServerList();
    void createPinger(const QString &server);
};

#endif // SERVERSMODEL_H
