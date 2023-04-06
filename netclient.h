#ifndef NETCLIENT_H
#define NETCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class NetClient;

class NetClientDestroyer
{
    private:
        NetClient *instance;
    public:
        ~NetClientDestroyer() { delete instance; }
        void initialize(NetClient *link){ instance = link; }
};

class NetClient : public QObject
{
    Q_OBJECT
private:
    static NetClient *instance;
    static NetClientDestroyer destroyer;
    QTcpSocket *TCPSocket;
protected:
    explicit NetClient(QObject *parent = nullptr);
    NetClient(const NetClient &) = delete;
    NetClient &operator = (NetClient &) = delete;
    ~NetClient() { TCPSocket->close(); }
    friend class NetClientDestroyer;
public:
    static NetClient *Connect();
    void SendData(QString data);
    signals:
        void ReceiveData(QString data);
    private slots:
        void ServerRead();
};



#endif // NETCLIENT_H
