#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QObject>
#include <QTcpSocket>

class ClientTCP
{
public:
    ClientTCP(QObject *parent);
private:
    QTcpSocket *tcpSocket = nullptr;
//    QDataStream in;
//    QString currentFortune;

//    QNetworkSession *networkSession = nullptr;
};

#endif // CLIENTTCP_H
