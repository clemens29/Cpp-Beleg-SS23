// Clemens Näther, 53035, 22/041/62

#include "cd.h"

using namespace std;

QString CD::getType()
{
    return "CD";
}

QString CD::printMedium()
{
    return this->getTitle() + '\n' + this->getAuthor() + '\n' + "1" + '\n' + this->getBorrower() + '\n';
}