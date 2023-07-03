#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QList>
#include "medium.h"
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveButtonClicked();
    void setupMediumTable();
    void setupPersonTable();
    void displayMedium(Medium* medium, int row);
    void displayPerson(Person* person, int row);
    void abbrButtonClicked();
    void abbrPersonButtonClicked();
    void addMediumButtonClicked();
    void addPersonButtonClicked();
    void closeEvent(QCloseEvent *event);
    void searchMediumButtonClicked();
    void searchPersonButtonClicked();
    void sortMedia();
    void sortPerson();
    void saveMediaListToFile();
    void savePersonListToFile();
    void loadMediaListFromFile();
    void loadPersonListFromFile();

    friend QDataStream& operator>>(QDataStream& in, QList<Medium*>& mediaList);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QList<Medium*> mediaList;
    QList<Person*> personList;
};
#endif // MAINWINDOW_H
