// Clemens Näther, 53035, 22/041/62

#ifndef DVD_H
#define DVD_H
#include "medium.h"

class DVD : public Medium
{
public:
    DVD() : Medium(){};
    DVD(QString title, QString author) : Medium(title, author){};

    QString getType();
    QString printMedium();
};

#endif // DVD_H
