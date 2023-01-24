#include "rational.h"
#include "math.h"

QChar TRational::SEPARATOR = separator;

TRational::TRational()
{
    a = 1;
    b = 1;
}

TRational::TRational(const int& x)
{
    a=x;
    b=1;
}

TRational::TRational(const int& x, const int& y)
{
    a=x;
    b=y;
}




void TRational::operator() (int new_a, int new_b){
    a = new_a;
    b = new_b;
}


void TRational::gcd()
{
    if (b < 0){
        a = a * (-1);
        b = b * (-1);
    }
    int num=a,denum=b;
    int i = 2;
    while(i<= min(abs(num), abs(denum)))
    {
        if ((num % i == 0) && (denum % i == 0))
        {
            num/=i;
            denum/=i;
            i = 2;
        }else{
            i++;
        }
    }
    a=num;
    b=denum;
}

TRational TRational::operator* (TRational r)
{
    TRational t;
    t.a=a*r.a;
    t.b=b*r.b;
    t.gcd();
    return t;
}

TRational TRational::operator* (int r)
{
    TRational t;
    t.a=a*r;
    t.b=b;
    t.gcd();
    return t;
}

TRational TRational::operator/ (TRational r)
{
    TRational t;
    t.a=a*r.b;
    t.b=b*r.a;
    t.gcd();
    return t;
}


TRational TRational::operator+ (TRational r)
{
    TRational t;
    t.a=a*r.b+r.a*b;
    t.b=b*r.b;
    t.gcd();
    return t;
}

TRational TRational::operator- ()
{
    TRational t;
    t.a=-a;
    t.b=b;
    return t;
}

TRational TRational::operator- (TRational r)
{
    TRational t;
    t.a=a*r.b-r.a*b;
    t.b=b*r.b;
    t.gcd();
    return t;
}


void TRational::operator= (TRational r)
{
    r.gcd();
    a = r.a;
    b = r.b;
}




bool TRational::operator== (TRational r)
{
    TRational t;
    t.a=a*r.b-r.a*b;
    t.b=b*r.b;
    if (t.a == 0){
        return true;
    }
    return false;
}


bool TRational::operator== (int i)
{
    if (a == i*b){
        return true;
    }
    return false;
}

bool TRational::operator!= (TRational r)
{
    TRational t;
    t.a=a*r.b-r.a*b;
    t.b=b*r.b;
    if (t.a == 0){
        return false;
    }
    return true;
}


bool TRational::operator!= (int i)
{
    if (a == i*b){
        return false;
    }
    return true;
}


bool TRational::operator> (TRational r)
{
    TRational t;
    t.a=a*r.b-r.a*b;
    t.b=b*r.b;
    return ((t.a/t.b) > 0);
}


bool TRational::operator> (int i)
{
    if ((a-i*b) > 0){
        return true;
    }
    return false;
}



bool TRational::operator< (TRational r)
{
    TRational t;
    t.a=a*r.b-r.a*b;
    t.b=b*r.b;
    t.gcd();
    return ((t.a/t.b) <0);
}


bool TRational::operator< (int i)
{
    if ((a-i*b) < 0){
        return true;
    }
    return false;
}



istream& operator>> (istream& is,TRational& r)
{
    is >> r.a >> r.b;
    return is;
}

ostream& operator<< (ostream& os,TRational r)
{
    r.gcd();
    if (r.b==1)
    {
        os<< r.a;
    }
    else
    {
        os<< r.a<<"/"<<r.b;
    }
    return os;
}

TRational sqrt(TRational r)
{
    r.gcd();
    TRational t;
    if ((r.a > 0) && (r.b > 0)){
        double a_s = sqrt(r.a);
        double b_s = sqrt(r.b);
        t.a = round(a_s * 10000);
        t.b = round(b_s * 10000);
        t.gcd();
    }else if (r.a == 0){
        t.a = 0;
        t.b = 1;
    }else {
        t.a = 0 ;
        t.b = 0;
    }
    //cout << t << endl;
    return t;
}


double TRational::doubleConvert()
{
    return a/b;
}


QString& operator<<(QString& s, TRational r){
    r.gcd();
    if (r.b==1)
    {
        s += QString().setNum(r.a);
    }
    else
    {
        s += QString().setNum(r.a) + "/"  + QString().setNum(r.b);
    }
    return s;
}


TRational::operator QString(){
    gcd();
    QString s("");
    if (b==1)
    {
        s += QString().setNum(a);
    }
    else
    {
        s += QString().setNum(a) + "/"  + QString().setNum(b);
    }
    return s;
}



TRational::TRational(const QByteArray& arr)
{
    int p = arr.indexOf(SEPARATOR.toLatin1());
    a = arr.left(p).toDouble();
    b = arr.right(arr.length()-p-1).toDouble();
}


QChar TRational::getSeparator(){
    return SEPARATOR;
}

QByteArray& operator>>(QByteArray& arr, TRational& r)
{
    int p = arr.indexOf(TRational::SEPARATOR.toLatin1());
    p = arr.indexOf(TRational::SEPARATOR.toLatin1(),p+1);
    if (p > 0)
    {
        r = TRational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

void TRational::setSeparator(QChar ch)
{
    SEPARATOR = ch;
}

