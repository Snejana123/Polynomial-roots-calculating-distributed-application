#include "application.h"

#include "application.h"

#include <iostream>

using namespace std;

TApplication::TApplication(int argc, char *argv[])
            : QApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 48998,
                         QHostAddress("127.0.0.1"), 48999};
    comm = new TCommunicator(pars, this);

    interface = new TInterface();
    interface->show();

    if (comm->isReady()){
        connect(comm,SIGNAL(recieved(QByteArray)),this,
                SLOT(fromCommunicator(QByteArray)));
        connect(interface,SIGNAL(request(QString)),
                this,SLOT(toCommunicator(QString)));
    }

}

void TApplication::fromCommunicator(QByteArray msg)
{
    interface->answer(QString(msg));
}

void TApplication::toCommunicator(QString msg)
{
    comm->write(QByteArray().append(msg.toLatin1()));
    comm->waitForBytesWritten(3000);
}
