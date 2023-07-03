#ifndef BOOK_H
#define BOOK_H
#include "medium.h"

class Book : public Medium {
public:
    Book():Medium() {};
    Book(QString title, QString author, QString type, QString borrower):Medium(title, author, type, borrower) {};

    QString printMedium();
};

#endif // BOOK_H
