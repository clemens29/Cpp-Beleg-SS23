#include "dvd.h"

DVD::DVD(QString title, QString author):Medium(title, author) {
    type = "DVD";
};