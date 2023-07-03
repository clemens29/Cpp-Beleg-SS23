#ifndef CD_H
#define CD_H
#include "medium.h"

class CD : public Medium{
public:
    CD():Medium() {};
    CD(QString title, QString author, QString type, QString borrower):Medium(title, author, type, borrower) {};

    QString printMedium();
};

#endif // CD_H
