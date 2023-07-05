// Clemens Näther, 53035, 22/041/62

#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QList>
#include <QLineEdit>
#include <QComboBox>
#include <QDate>

class Person
{
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

    // zum Speichern in der Datei
    QString printPerson();
};

#endif // PERSON_H
