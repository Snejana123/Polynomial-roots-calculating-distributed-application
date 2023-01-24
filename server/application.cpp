#include "application.h"
#include "rational.h"
#include "common.h"
#include "servertcp.h"
#include "polinom.h"

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParamsServer pars = {QHostAddress("127.0.0.1"), 48999};
    TServerTcp *server = new TServerTcp(pars, this);

    connect(server,SIGNAL(recieved(QTcpSocket*, QByteArray)),this,SLOT( recieve(QTcpSocket*, QByteArray)));
}

void TApplication::recieve(QTcpSocket* connSocket,QByteArray msg)
{
    QString answer(""), s("");
    TRational a, b, c, x, v;
    msg >> a >> b>> c;
    TPolinom p(a,b,c);
    int pos = msg.indexOf(separator.toLatin1());
    int t = msg.left(pos).toInt();
    switch (t)
    {
        case VALUE_REQUEST:
            msg = msg.right(msg.length()-pos-1);
            msg>>x;
            v = p.value(x);
            s<<(QString)x<<(QString)v;
            answer<<QString().setNum(VALUE_ANSWER);
            answer += s;
            break;
        case PRINT_CLASSIC_REQUEST:
            p.setPrintMode(EPrintModeClassic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case PRINT_CANONIC_REQUEST:
            p.setPrintMode(EPrintModeCanonic);
            s << p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case VALUE_ROOT:
            p.getRoots();
            p.printRoots(s);
            answer<<QString().setNum(PRINT_ROOTS)<<s;
            break;
        default: return;
    }
    connSocket->write(QByteArray().append(answer.toLatin1()));
    connSocket->waitForBytesWritten();
}
