#include "netclient.h"

NetClient::NetClient(QObject *parent) : QObject(parent)
{
    TCPSocket = new QTcpSocket(this);

    TCPSocket->connectToHost("127.0.0.1", 33333);
    connect(TCPSocket, &QTcpSocket::readyRead,
            this, &NetClient::ServerRead);
    if(TCPSocket->isOpen())
        qDebug()<<"open";
}

NetClient* NetClient::Connect()
{
    if (!instance)
    {
        instance = new NetClient();
        destroyer.initialize(instance);
    }
    return instance;
}

void NetClient::SendData(QString data)
{
    TCPSocket->write(data.toUtf8());
    qDebug() << "Send:" << data;
}

void NetClient::ServerRead()
{
    QString data_input;
    //while(TCPSocket->bytesAvailable()>0)
    //{
        data_input = TCPSocket->readAll();
    //}
    qDebug() << "Get:" << data_input;
}

NetClient *NetClient::instance;
NetClientDestroyer NetClient::destroyer;
