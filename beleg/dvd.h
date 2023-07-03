#ifndef DVD_H
#define DVD_H
#include "medium.h"

class DVD : public Medium{
public:
    DVD():Medium() {};
    DVD(QString title, QString author, QString type, QString borrower):Medium(title, author, type, borrower) {};

    QString printMedium();
};

#endif // DVD_H
