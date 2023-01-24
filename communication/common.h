#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    VALUE_REQUEST = 1,
    VALUE_ROOT,
    PRINT_CLASSIC_REQUEST,
    PRINT_CANONIC_REQUEST,

    VALUE_ANSWER,
    PRINT_ANSWER,
    PRINT_ROOTS,
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
