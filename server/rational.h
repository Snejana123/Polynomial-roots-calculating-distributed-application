#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <QString>
#include "common.h"

using namespace std;

class TRational
{
    static QChar SEPARATOR;
    int a;
    int b;

public:
    TRational();
    TRational(const int&);
    TRational(const int& x, const int& y);
    TRational(const QByteArray&);
    //TRational(int x, int y);
    TRational operator* (TRational);
    TRational operator* (int);
    TRational operator+ (TRational);
    TRational operator- ();
    TRational operator- (TRational);
    TRational operator/ (TRational);
    void operator= (TRational);
    void operator() (int, int);
    bool operator== (TRational);
    bool operator== (int );
    bool operator!= (TRational);
    bool operator!= (int );
    bool operator> (TRational);
    bool operator> (int );
    bool operator< (TRational);
    bool operator< (int );
    void gcd ();
    double doubleConvert();
    friend istream& operator>> (istream&,TRational&);
    friend ostream& operator<< (ostream&,TRational);

    friend QString& operator<<(QString&, TRational);

    friend TRational sqrt(TRational);
    friend QByteArray& operator>>(QByteArray& , TRational&);


    operator QString();

    static QChar getSeparator();
    //QString QString();
    void setSeparator(QChar);

};

#endif // RATIONAL_H
