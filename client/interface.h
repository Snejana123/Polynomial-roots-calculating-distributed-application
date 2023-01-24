#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
//#include "polinom.h"

class TInterface : public QWidget
{
    Q_OBJECT

    QLabel *name_a, *delimeter_a;
    QLineEdit *a_num, *a_den;
    QLabel *name_b, *delimeter_b;
    QLineEdit *b_num, *b_den;
    QLabel *name_c, *delimeter_c;
    QLineEdit *c_num, *c_den;
    QLabel *name_x, *delimeter_x;
    QLineEdit *x_num, *x_den;


    QPushButton *value_btn;
    QPushButton *root_btn;
    QPushButton *print_classic_btn;
    QPushButton *print_canonical_btn;

    QLabel *output;

public:
    explicit TInterface(QWidget *parent = nullptr);
    ~TInterface();

public slots:
    /*void value();
    void print_classic();
    void print_canonical();
    void print_roots();*/

    void answer(QString);

private slots:
    void formRequest();

signals:
    void request(QString);


};

#endif // TINTERFACE_H
