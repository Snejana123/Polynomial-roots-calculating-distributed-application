#include "interface.h"
#include "common.h"

#include <iostream>

using namespace std;

TInterface::TInterface(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Roots calculator");
    setFixedSize(340, 250);

    name_a = new QLabel("a =", this);
    name_a -> setGeometry(70,20,30,25);
    a_num = new QLineEdit("1", this);
    a_num -> setGeometry(110,20,50,25);
    delimeter_a = new QLabel("/", this);
    delimeter_a->setGeometry(170,20,30,25);
    a_den = new QLineEdit("1", this);
    a_den -> setGeometry(210,20,50,25);

    name_b = new QLabel("b =", this);
    name_b -> setGeometry(70,50,30,25);
    b_num = new QLineEdit("1", this);
    b_num -> setGeometry(110,50,50,25);
    delimeter_b = new QLabel("/", this);
    delimeter_b->setGeometry(170,50,30,25);
    b_den = new QLineEdit("1", this);
    b_den -> setGeometry(210,50,50,25);

    name_c = new QLabel("c =", this);
    name_c -> setGeometry(70,80,30,25);
    c_num = new QLineEdit("1", this);
    c_num -> setGeometry(110,80,50,25);
    delimeter_c = new QLabel("/", this);
    delimeter_c->setGeometry(170,80,30,25);
    c_den = new QLineEdit("1", this);
    c_den -> setGeometry(210,80,50,25);

    name_x = new QLabel("x =", this);
    name_x -> setGeometry(70,110,30,25);
    x_num = new QLineEdit("1", this);
    x_num -> setGeometry(110,110,50,25);
    delimeter_x = new QLabel("/", this);
    delimeter_x->setGeometry(170,110,30,25);
    x_den = new QLineEdit("1", this);
    x_den -> setGeometry(210,110,50,25);

    value_btn = new QPushButton ("value",this);
    value_btn -> setGeometry(30, 150, 60, 30);
    root_btn = new QPushButton("roots", this);
    root_btn -> setGeometry(100, 150, 60, 30);
    print_classic_btn = new QPushButton ("classic", this);
    print_classic_btn -> setGeometry(180, 150, 60, 30);
    print_canonical_btn = new QPushButton ("canon", this);
    print_canonical_btn -> setGeometry(250, 150, 60, 30);

    output = new QLabel(this);
    output -> setGeometry(10, 200, 320, 30);

    connect(value_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(print_classic_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(print_canonical_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(root_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete name_a;
    delete delimeter_a;
    delete a_num;
    delete a_den;

    delete name_b;
    delete delimeter_b;
    delete b_num;
    delete b_den;

    delete name_c;
    delete delimeter_c;
    delete c_num;
    delete c_den;

    delete name_x;
    delete delimeter_x;
    delete x_num;
    delete x_den;

    delete value_btn;
    delete root_btn;
    delete print_classic_btn;
    delete print_canonical_btn;
    delete output;
}


void TInterface::formRequest()
{
    QString msg;
    msg << a_num->text() << a_den->text();
    msg << b_num->text() << b_den->text();
    msg << c_num->text() << c_den->text();
    QPushButton *btn = (QPushButton*)sender();
    if (btn == value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        msg << x_num->text() << x_den->text();
    }else if (btn == print_classic_btn){
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    }else if (btn == print_canonical_btn){
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
    }else if (btn == root_btn){
        msg << QString().setNum(VALUE_ROOT);
    }
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += " = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            break;
        case PRINT_ANSWER:
            text = "p(x) = ";
            text += msg;
            output->setText(text);
            break;
        case PRINT_ROOTS:
            if(msg.indexOf(separator) == -1){
                text += msg;
            }else{
                text += msg.left(p);
            }
            output->setText(text);
            break;
        default:
            break;
    }
}

