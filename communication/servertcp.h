#ifndef TSERVERTSP_H
#define TSERVERTSP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkProxy>


struct TCommParamsServer
{
    QHostAddress sHost;
    quint16      sPort;
};



class TServerTcp : public QTcpServer
{

    Q_OBJECT

    bool         ready;
    //QTcpSocket *socket;
    //TCommParams  params;

public:
    TServerTcp(TCommParamsServer&, QObject*);
    bool isReady();



signals:
    void connRead(QTcpSocket *);
    void recieved(QTcpSocket *, QByteArray);



private slots:
    //void recieve();
    void send(QTcpSocket *, QByteArray);
    void recieve(QTcpSocket *);
    void newConnection();


};

#endif // TSERVERTSP_H
