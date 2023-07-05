// Clemens Näther, 53035, 22/041/62

#ifndef BOOK_H
#define BOOK_H
#include "medium.h"

class Book : public Medium
{
public:
    Book() : Medium(){};
    Book(QString title, QString author) : Medium(title, author){};

    QString getType();
    QString printMedium();
};

#endif // BOOK_H
