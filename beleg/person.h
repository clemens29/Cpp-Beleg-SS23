#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QList>
#include <QLineEdit>
#include <QComboBox>
#include <QDate>

class Person {
private:
    QString firstname;
    QString surname;
    QDate birthday;
    QChar gender;

public:
    Person();
    Person(QString firstname, QString surname, QDate birthday, QChar gender);

    // getter & setter
    void setFirstname(QString name);
    void setSurname(QString name);
    void setBirthday(QDate Birthday);
    void setGender(QChar gender);

    QString getFirstname();
    QString getSurname();
    QDate getBirthday();
    QChar getGender();

    void printPerson();
};

#endif // PERSON_H
