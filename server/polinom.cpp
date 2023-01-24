#include "polinom.h"
#include "number.h"
#include "math.h"



TPolinom::TPolinom(number x, number y, number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
    roots[0] = 0;
    roots[1] = 0;
    roots[2] = 0;
};


void TPolinom::operator() (number x, number y, number z){
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
}


ostream& operator<< (ostream& os, TPolinom& p)
{
    if (p.printMode == EPrintModeClassic)
    {
        if (p.a == 1){
            os << "x^2";
        }else{
            os << p.a << "x^2";
        }
        if (p.b == 1){
            os << "+" << "x";
        }else if (p.b > 0){
            os << "+" << p.b << "x";
        }else if (p.b != 0){
            os << p.b << "x";
        }
        if (p.c > 0){
            os << "+" << p.c;
        }else if (p.c != 0){
            os << p.c;
        }
        return os;
    }
    p.getRoots();
    if ((p.roots[0] == 0) || (p.roots[0] == -1)){
        os << "It is impossimble to represent an expression in canonic form.";
    }else if (p.roots[0] == 1){
        if (p.a != 1)
            os <<p.a;
        if (p.roots[1] > 0){
            os << "(x - " << p.roots[1] << ")^2";
        }else if(p.roots[1] < 0){
            os << "(x + " << - p.roots[1] << ")^2";
        }else{
            os << "x^2";
        }
    }else if (p.roots[0] == 2){
        if (p.a != 1)
            os <<p.a;
        if ((p.roots[1] == 0) && (p.roots[2] == 0)){
            os << "x^2";
        }
        if (p.roots[1] > 0){
            os << "(x - " << p.roots[1] << ")";
        }else if(p.roots[1] < 0){
            os << "(x + " << - p.roots[1] << ")";
        }else{
            os << "x";
        }
        if (p.roots[2] > 0){
            os << "(x - " << p.roots[2] << ")";
        }else if(p.roots[2] < 0){
            os << "(x + " << - p.roots[2] << ")";
        }else{
            os << "x";
        }
    }
    return os;
}



QString& operator<< (QString& s, TPolinom& p)
{
    if (p.printMode == EPrintModeClassic)
    {
        if (p.a == 1){
            s += "x^2";
        }else{
            s << p.a;
            s += "x^2";
        }
        if (p.b == 1){
            s += "+ x";
        }else if (p.b > 0){
            s += "+";
            s << p.b;
            s += "x";
        }else if (p.b != 0){
            s << p.b ;
            s += "x";
        }
        if (p.c > 0){
            s += "+";
            s << p.c;
        }else if (p.c != 0){
            s << p.c;
        }
        return s;
    }
    p.getRoots();
    if ((p.roots[0] == 0) || (p.roots[0] == -1)){
        s += "Impossimble to represent an expression.";
    } else if (p.roots[0]==1){
        if (p.a != 1)
            s << p.a;
        if (p.roots[1] > 0){
            s += "(x - " ;
            s << p.roots[1];
            s += ")^2";
        }else if(p.roots[1] < 0){
            s += "(x + ";
            s << - p.roots[1];
            s += ")^2";
        }else{
            s += "x^2";
        }

    }else if (p.roots[0] == 2){
        if (p.a != 1)
            s <<p.a;
        if ((p.roots[1] == 0) && (p.roots[2] == 0)){
            s += "x^2";
        }
        if (p.roots[1] > 0){
            s += "(x - " ;
            s << p.roots[1];
            s += ")";
        }else if(p.roots[1] < 0){
            s += "(x + " ;
            s << - p.roots[1];
            s += ")";
        }else{
            s += "x";
        }
        if (p.roots[2] > 0){
            s += "(x - ";
            s << p.roots[2];
            s += ")";
        }else if(p.roots[2] < 0){
            s += "(x + ";
            s << - p.roots[2];
            s += ")";
        }else{
            s += "x";
        }
    }
    return s;
}



number TPolinom::value(number x)
{
    return a*x*x + b*x + c;
}

void TPolinom::setPrintMode(EPrintMode  m)
{
    printMode = m;
}

void TPolinom::getRoots()
{
   number D = b*b - a*c*4;
   //cout << D << endl;
    if (D < 0){
        roots[0] = 0;
    }else if(D == 0){
        roots[0] = 1;
        if (number ( -b / (a*2)) == -b / (a*2))
        {
           roots[1] = -b / (a*2);
        }else{
            roots[0] = -1;
        }
    }else{
        roots[0] = 2;
        if (( number((-b + sqrt(D) )/ (a*2) ) == (-b + sqrt(D) )/ (a*2) ) && ( number((-b - sqrt(D) )/ (a*2)) == (-b - sqrt(D) )/ (a*2))){
            roots[1] = (-b + sqrt(D) )/ (a*2);
            roots[2] = (-b - sqrt(D) )/ (a*2);
        }else{
            roots[0] = -1;
        }
    }
}

void TPolinom::printRoots()
{
    if (roots[0] == -1)
    {
        cout << "Application work only with integer roots." << endl;
    }else if(roots[0] == 0)
    {
        cout << "NO ROOTS" << endl;
    }else if (roots[0] == 1){
        cout << "root: " << roots[1] << endl;
    }else{
        cout << "root 1: " << roots[1] << endl;
        cout << "root 2: " << roots[2] << endl;
    }
}


void TPolinom::printRoots(QString& s)
{
    if (roots[0] == -1)
    {
        s += "Application work only with integer roots.";
    }else if(roots[0] == 0)
    {
        s+= "NO ROOTS";
    }else if (roots[0] == 1){
        s += "root: " ;
        s << roots[1];
    }else{
        s += "root 1: " ;
        s << roots[1];
        s += "\n";
        s += "root 2: ";
        s << roots[2];
    }
}
