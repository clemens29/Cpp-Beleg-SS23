#include "cd.h"

DVD::getType() {
    return 1;
}

Book::printMedium() {
    out << medium->getTitle() << '\n';
    out << medium.getAuthor() << '\n';
    out << "1" << '\n';
    out << medium->getBorrower() << '\n';
}