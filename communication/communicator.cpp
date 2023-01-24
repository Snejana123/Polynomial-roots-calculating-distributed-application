#include "communicator.h"

#include <iostream>

using namespace std;

TCommunicator::TCommunicator(TCommParams& pars, QObject *parent) : QTcpSocket(parent)
{
    params = pars;
    bind(params.rHost, 0,
                QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    setSocketOption(QAbstractSocket::KeepAliveOption, 1);
    setSocketOption(QAbstractSocket::LowDelayOption, 1);

    connect(this, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(connected()), this, SLOT(connectedWithHost()));
    connect(this, SIGNAL(disconnected()), this, SLOT(disconnectedFromHost()));
    connectToHost(params.sHost, params.sPort, ReadWrite);
    ready = waitForConnected(3000);
    while((state() != 2) && (state() != 3)){
        connectToHost(params.sHost, params.sPort, ReadWrite);
        ready = waitForConnected(3000);
        cout << "STATE" << state() << endl;
        if (state() == 6){
            break;
        }
    }
    cout << "STATE" << state()<< endl;

    if (ready){
        cout << "Connected" << endl;
    }

}


void TCommunicator::error(QAbstractSocket::SocketError error) {
    cout << "Socket error " << error << ":  " << errorString().toStdString()<<endl;
}


void TCommunicator::connectedWithHost(){
    cout << "connectedWithHost" << endl;
    connect(this, SIGNAL(readyRead()), this, SLOT(recieve()));
}

void TCommunicator::disconnectedFromHost(){
    setOpenMode(NotOpen);
    abort();
    close();
    disconnect(this, SIGNAL(readyRead()), this, SLOT(recieve()));
    ready = false;
}

bool TCommunicator::isReady()
{
    return ready;
}

void TCommunicator::send(QByteArray msg)
{
    if (ready)
    {
        write(msg);
    }
}

void TCommunicator::recieve()
{

    QByteArray msg;
    msg = readAll();
    emit recieved(msg);
}




TCommunicator::~TCommunicator(){
}
