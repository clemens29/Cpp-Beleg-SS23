#ifndef MEDIUM_H
#define MEDIUM_H

#include <QObject>
#include <QString>
#include <QList>
#include <QUuid>
#include <QLineEdit>
#include <QComboBox>

class Medium
{

private:
    QString title;
    QString author;
    QString borrower;

public:
    Medium();
    Medium(QString title, QString author);

    // getter & setterdshsd
    void setTitle(QString title);
    void setAuthor(QString author);
    void setBorrower(QString borrower);

    QString getTitle();
    QString getAuthor();
    virtual QString getType() = 0;
    QString getBorrower();

    // zum Speichern in der Datei
    virtual QString printMedium() = 0;

};

#endif // MEDIUM_H
