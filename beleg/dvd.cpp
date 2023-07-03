#include "dvd.h"

DVD::getType() {
    return 2;
}

Book::printMedium() {
    out << medium->getTitle() << '\n';
    out << medium.getAuthor() << '\n';
    out << "0" << '\n';
    out << medium->getBorrower() << '\n';
}