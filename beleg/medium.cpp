#include <QLineEdit>
#include <QComboBox>
#include "medium.h"

Medium::Medium() {
    title = author = type = borrower = QString("");
}

Medium::Medium(QString title, QString author) {
    this->title = title;
    this->author = author;
    this->borrower = QString("");
}

void Medium::printMedium() {
    qDebug() << title << author << type << borrower;
}

// Getter
QString Medium::getTitle() {
    return title;
}

QString Medium::getAuthor() {
    return author;
}

QString Medium::getBorrower() {
    return borrower;
}

// Setter^
void Medium::setTitle(QString title) {
    this->title = title;
}

void Medium::setAuthor(QString author) {
    this->author = author;
}

void Medium::setBorrower(QString borrower) {
    this->borrower = borrower;
}
