#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

struct TCommParams
{
    QHostAddress rHost;
    quint16      rPort;
    QHostAddress sHost;
    quint16      sPort;
};

class TCommunicator : public QTcpSocket
{
    Q_OBJECT

    bool         ready = false;
    TCommParams  params;

public:
    TCommunicator(TCommParams&,QObject *parent = nullptr);
    bool isReady();
    ~TCommunicator();

signals:
    void recieved(QByteArray);

public slots:
    void send(QByteArray);
    void connectedWithHost();
    void disconnectedFromHost();
    void error(QAbstractSocket::SocketError error);

private slots:
    void recieve();
    //void connectionError_Handler(QAbstractSocket::SocketError);

};

#endif // COMMUNICATOR_H
