#include <QLineEdit>
#include <QComboBox>
#include "person.h"

Person::Person() {
    firstname = surname = QString("");
    birthday = QDate(1900, 1, 1);
    gender = QChar('n');
}

Person::Person(QString firstname, QString surname, QDate birthday, QChar gender) {
    this->firstname = firstname;
    this->surname = surname;
    this->birthday = birthday;
    this->gender = gender;
}

void Person::printPerson() {
    qDebug() << firstname << surname << birthday.toString("dd.mm.yyyy") << gender;
}

QString Person::getFirstname() {
    return firstname;
}

QString Person::getSurname() {
    return surname;
}

QDate Person::getBirthday() {
    return birthday;
}

QChar Person::getGender() {
    return gender;
}

void Person::setFirstname(QString name) {
    this->firstname = name;
}

void Person::setSurname(QString name) {
    this->surname = name;
}

void Person::setBirthday(QDate birthday) {
    this->birthday = birthday;
}

void Person::setGender(QChar gender) {
    this->gender = gender;
}
