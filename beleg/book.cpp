// Clemens Näther, 53035, 22/041/62

#include "book.h"
#include <iostream>

using namespace std;

QString Book::getType() {
    return "Buch";
}

QString Book::printMedium() {
    return this->getTitle() + '\n' + this->getAuthor() + '\n' + "0" + '\n' + this->getBorrower() + '\n';
}
