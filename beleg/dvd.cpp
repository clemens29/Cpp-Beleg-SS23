#include "dvd.h"

using namespace std;

QString DVD::getType() {
    return "DVD";
}

QString DVD::printMedium() {
    return this->getTitle() + '\n' + this->getAuthor() + '\n' + "2" + '\n' + this->getBorrower() + '\n';
}