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

    // getter & setter
    void setTitle(QString title);
    void setAuthor(QString author);
    void setBorrower(QString borrower);

    QString getTitle();
    QString getAuthor();
    virtual QString getType();
    QString getBorrower();

    virtual QString printMedium();

};

#endif // MEDIUM_H
