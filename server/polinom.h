#ifndef TPOLINOM_H
#define TPOLINOM_H

#include "number.h"
#include <iostream>

using namespace std;

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolinom
{
    EPrintMode printMode;
    number a, b, c;
public:
    number roots[3] = {0, 0, 0};
    TPolinom(number, number, number);
    void operator() (number, number, number);
    friend ostream& operator<< (ostream&, TPolinom&);
    friend QString& operator<< (QString&, TPolinom&);
    number value(number);
    void setPrintMode(EPrintMode);
    void getRoots();
    void printRoots();
    void printRoots(QString& s);
};

#endif // TPOLINOM_H
