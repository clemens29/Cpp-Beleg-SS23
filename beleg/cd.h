#ifndef CD_H
#define CD_H
#include "medium.h"

class CD : public Medium{
public:
    CD():Medium() {};
    CD(QString title, QString author):Medium(title, author) {};

    QString getType();
    QString printMedium();
};

#endif // CD_H
