#include "servertcp.h"
#include <iostream>

using namespace std;

TServerTcp::TServerTcp(TCommParamsServer& pars, QObject *parent): QTcpServer(parent)
{
    setProxy(QNetworkProxy::NoProxy);
    if (listen(pars.sHost, pars.sPort)){
        connect(this, SIGNAL(newConnection()), this, SLOT(newConnection()));
    }

}

void TServerTcp::newConnection(){
    QTcpSocket *toCommunicator = nextPendingConnection();
    while(true){
        if (toCommunicator-> waitForReadyRead(500)){
            quint64 size = toCommunicator->bytesAvailable();
            if (size > 0){
                QByteArray msg(size,'\0');
                toCommunicator->read(msg.data(), size);
                emit recieved(toCommunicator, msg);
            }
        }
        if ((toCommunicator->state() != 3) || (! toCommunicator->isOpen()) || (! toCommunicator -> isValid())){
            break;
        }
    }
}


void TServerTcp::recieve(QTcpSocket *connSocket){
    quint64 size = connSocket->bytesAvailable();
    if (size > 0){
        QByteArray msg(size,'\0');
        connSocket->read(msg.data(), size);
        emit recieved(connSocket, msg);
    }
}


void TServerTcp::send(QTcpSocket *connSocket, QByteArray msg){
    connSocket->write(msg);
}
