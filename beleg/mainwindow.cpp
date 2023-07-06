// Clemens Näther, 53035, 22/041/62

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include "medium.h"
#include "person.h"
#include "book.h"
#include "cd.h"
#include "dvd.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Hinzufügen eines neuen Mediums
    QDialogButtonBox *saveBox_media = ui->saveBox_media;
    QObject::connect(saveBox_media, &QDialogButtonBox::accepted, [this]()
                     {
        QLineEdit *title_input = ui->title_input;
        QLineEdit *author_input = ui->author_input;
        QComboBox *type_input = ui->type_input;
        if (title_input->text() != QString("")) {
            QTableWidget *media_table = ui->media_table;
            Medium* new_medium;
            if (type_input->currentText() == "Buch")
                new_medium = new Book(title_input->text(), author_input->text());
            else if (type_input->currentText() == "CD")
                new_medium = new CD(title_input->text(), author_input->text());
            else if (type_input->currentText() == "DVD")
                new_medium = new DVD(title_input->text(), author_input->text());
            abbrButtonClicked();
            mediaList.append(new_medium);
            media_table->setRowCount(mediaList.size());
            displayMedium(new_medium, media_table->rowCount()-1);
        } else {
            QLabel *warning_media = ui->warning_media;
            warning_media->setVisible(true);
        } });

    QObject::connect(saveBox_media, &QDialogButtonBox::rejected, [this]()
                     { abbrButtonClicked(); });

    // Hinzufügen einer neuen Person
    QDialogButtonBox *saveBox_person = ui->saveBox_person;
    QObject::connect(saveBox_person, &QDialogButtonBox::accepted, [this]()
                     {
        QLineEdit *firstname_input = ui->firstname_input;
        QLineEdit *surname_input = ui->surname_input;
        QDateEdit *birthday_input = ui->birthday_input;
        QRadioButton *gender_input_m = ui->gender_input_m;
        QRadioButton *gender_input_w = ui->gender_input_w;
        QRadioButton *gender_input_d = ui->gender_input_d;
        if (firstname_input->text() != QString("") && surname_input->text() != QString("")) {
            QTableWidget *person_table = ui->person_table;
            char c;
            if (gender_input_w->isChecked()) c = 'w';
            else if (gender_input_m->isChecked()) c = 'm';
            else if (gender_input_d->isChecked()) c = 'd';
            else c = 'n';
            Person *new_person = new Person(firstname_input->text(), surname_input->text(), birthday_input->date(), c);
            abbrPersonButtonClicked();
            personList.append(new_person);
            person_table->setRowCount(personList.size());
            displayPerson(new_person, person_table->rowCount()-1);
        } else {
            QLabel *warning_person = ui->warning_person;
            warning_person->setVisible(true);
        } });

    QObject::connect(saveBox_person, &QDialogButtonBox::rejected, [this]()
                     { abbrPersonButtonClicked(); });

    // Suchen nach Medium
    QDialogButtonBox *searchBox_media = ui->searchBox_media;
    QObject::connect(searchBox_media, &QDialogButtonBox::accepted, [this]()
                     {
        QTableWidget *media_table = ui->media_table;
        media_table->setRowCount(0);
        QString title_input_search = ui->title_input_search->text();
        QString author_input_search = ui->author_input_search->text();
        int i = 0;
        for (Medium* medium : mediaList) {
            if (title_input_search != QString("") && medium->getTitle() != title_input_search) {
                continue;
            }
            if (author_input_search != QString("") && medium->getAuthor() != author_input_search) {
                continue;
            }
            media_table->setRowCount(i+1);
            displayMedium(medium, i);
            i++;

        } });

    // Suchen nach Person
    QDialogButtonBox *searchBox_person = ui->searchBox_person;
    QObject::connect(searchBox_person, &QDialogButtonBox::accepted, [this]()
                     {
        QTableWidget* person_table = ui->person_table;
        person_table->clear();
        person_table->setRowCount(0);
        QStringList headers;
        headers << "Vorname" << "Nachname" << "Geburtstag" << "Geschlecht" << "";
        person_table->setHorizontalHeaderLabels(headers);

        QString firstname_input_search = ui->firstname_input_search->text();
        QString surname_input_search = ui->surname_input_search->text();
        int i = 0;
        for ( Person* person : personList) {
            if (firstname_input_search != QString("") && person->getFirstname() != firstname_input_search) {
                continue;
            }
            if (surname_input_search != QString("") && person->getSurname() != surname_input_search) {
                continue;
            }
            person_table->setRowCount(i+1);
            displayPerson(person, i);
            i++;
        } });

    // Drücken des "Medium hinzufügen Buttons"
    QPushButton *addButton = this->findChild<QPushButton *>("addmedia");
    QObject::connect(addButton, &QPushButton::clicked, this, [this]()
                     { addMediumButtonClicked(); });

    // Widgets initial verstecken
    QWidget *addMediaWidget = this->findChild<QWidget *>("add_media");
    addMediaWidget->setVisible(false);

    QLabel *warning_media = this->findChild<QLabel *>("warning_media");
    warning_media->setVisible(false);

    loadMediaListFromFile();
    loadPersonListFromFile();

    // Anzeigen der Daten, welche aus den Dateien geladen wurden
    setupMediumTable();
    for (int i = 0; i < mediaList.size(); ++i)
    {
        Medium *medium = mediaList.at(i);
        displayMedium(medium, i);
    }

    setupPersonTable();
    for (int i = 0; i < personList.size(); ++i)
    {
        Person *person = personList.at(i);
        displayPerson(person, i);
    }

    // Drücken des "Person hinzufügen" Buttons
    QPushButton *addPersonButton = this->findChild<QPushButton *>("addperson");
    QObject::connect(addPersonButton, &QPushButton::clicked, this, [this]
                     { addPersonButtonClicked(); });

    // Widgets initial verstecken
    QWidget *addPersonWidget = this->findChild<QWidget *>("add_person");
    addPersonWidget->setVisible(false);

    QLabel *warning_person = ui->warning_person;
    warning_person->setVisible(false);

    // Widgets und Buttons für die Suche nach Medium und Person
    QWidget *search_media = ui->search_media;
    search_media->setVisible(false);

    QPushButton *search_media_btn = ui->search_media_btn;
    QObject::connect(search_media_btn, &QPushButton::clicked, this, [this]
                     { searchMediumButtonClicked(); });

    QWidget *search_person = ui->search_person;
    search_person->setVisible(false);

    QPushButton *search_person_btn = ui->search_person_btn;
    QObject::connect(search_person_btn, &QPushButton::clicked, this, [this]
                     { searchPersonButtonClicked(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Erstellen der Tabelle für die Medien
void MainWindow::setupMediumTable()
{

    QTableWidget *media_table = ui->media_table;
    media_table->clear();
    media_table->setRowCount(mediaList.size());
    media_table->setColumnCount(6);

    QStringList headers;
    headers << "Titel"
            << "Autor"
            << "Typ"
            << "Ausleiher"
            << ""
            << "";
    media_table->setHorizontalHeaderLabels(headers);

    media_table->setSortingEnabled(true);
}

// Anzeigen eines Mediums in der Tabelle
void MainWindow::displayMedium(Medium *medium, int row)
{
    QTableWidget *media_table = ui->media_table;

    QTableWidgetItem *titleItem = new QTableWidgetItem(medium->getTitle());
    media_table->setItem(row, 0, titleItem);
    QTableWidgetItem *authorItem = new QTableWidgetItem(medium->getAuthor());
    media_table->setItem(row, 1, authorItem);
    QTableWidgetItem *typeItem = new QTableWidgetItem(medium->getType());
    media_table->setItem(row, 2, typeItem);
    QTableWidgetItem *borrowerItem = new QTableWidgetItem(medium->getBorrower());
    media_table->setItem(row, 3, borrowerItem);

    // state button für entweder Ausleihe (wenn kein borrower) oder Rückgabe (wenn ein borrower vorhanden)
    QPushButton *state;
    if (!medium->getBorrower().isEmpty())
        state = new QPushButton("Rückgabe");
    else
        state = new QPushButton("Ausleihen");
    media_table->setCellWidget(row, 4, state);

    QPushButton *deleteButton = new QPushButton("Löschen");
    media_table->setCellWidget(row, 5, deleteButton);

    // Drücken des "Ausleihen" / "Rückgabe" Buttons
    connect(state, &QPushButton::clicked, [medium, state, this, row, media_table]()
            {
        if (!medium->getBorrower().isEmpty()) {
            // Rückgabe
            QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Bestätigung", "Möchten Sie " + medium->getTitle() + " zurückgeben?", QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                medium->setBorrower("");
                QTableWidgetItem* borrowerItem = new QTableWidgetItem(medium->getBorrower());
                media_table->setItem(row, 3, borrowerItem);
                state->setText("Ausleihen");
                media_table->update();
            }
        } else {
            // Ausleihe
            // Vorname eingeben
            QString firstname = QInputDialog::getText(this, "Ausleihe", "Geben Sie den Vornamen der Person ein:");
            if (firstname.isEmpty())
                return;

            // Nachname eingeben
            QString surname = QInputDialog::getText(this, "Ausleihe", "Geben Sie den Nachnamen der Person ein:");
            if (surname.isEmpty())
                return;

            // Überprüfen, ob die ausgewählte Person in der Liste personList enthalten ist
            bool personFound = false;
            for (Person* person : personList) {
                if (person->getFirstname() == firstname && person->getSurname() == surname) {
                    personFound = true;
                    break;
                }
            }

            if (personFound) {
                QString selectedPerson = firstname + " " + surname;
                medium->setBorrower(selectedPerson);
                QTableWidgetItem* borrowerItem = new QTableWidgetItem(medium->getBorrower());
                media_table->setItem(row, 3, borrowerItem);
                state->setText("Rückgabe");
                media_table->update();
            } else {
                QMessageBox::warning(nullptr, "Fehler", "Die ausgewählte Person ist nicht gültig.");
            }
        } });

    // Löschen des Mediums
    connect(deleteButton, &QPushButton::clicked, [this, medium, row, media_table]()
            {
        QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Bestätigung", "Möchten Sie " + medium->getTitle() + " wirklich löschen?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            media_table->removeRow(row);
            mediaList.removeOne(medium);
        } });

    media_table->resizeColumnsToContents();
}

// Erstellen der Tabelle für die Personen
void MainWindow::setupPersonTable()
{
    QTableWidget *person_table = ui->person_table;
    person_table->clear();
    person_table->setRowCount(personList.size());
    person_table->setColumnCount(5);

    // Überschriften für die Spalten
    QStringList headers;
    headers << "Vorname"
            << "Nachname"
            << "Geburtsdatum"
            << "Geschlecht"
            << "";
    person_table->setHorizontalHeaderLabels(headers);

    person_table->setSortingEnabled(true);
}

// Anzeigen einer Person in der Tabelle
void MainWindow::displayPerson(Person *person, int row)
{
    QTableWidget *person_table = ui->person_table;

    QTableWidgetItem *firstnameItem = new QTableWidgetItem(person->getFirstname());
    person_table->setItem(row, 0, firstnameItem);
    QTableWidgetItem *surnameItem = new QTableWidgetItem(person->getSurname());
    person_table->setItem(row, 1, surnameItem);
    QTableWidgetItem *birthdayItem = new QTableWidgetItem(person->getBirthday().toString("dd.MM.yyyy"));
    person_table->setItem(row, 2, birthdayItem);
    QString g = person->getGender();
    if (g == "w")
        g = QString("weiblich");
    else if (g == "m")
        g = QString("männlich");
    else if (g == "d")
        g = QString("divers");
    QTableWidgetItem *genderItem = new QTableWidgetItem(g);
    person_table->setItem(row, 3, genderItem);

    // Löschen einer Person
    QPushButton *deleteButton = new QPushButton("Löschen");
    person_table->setCellWidget(row, 4, deleteButton);

    connect(deleteButton, &QPushButton::clicked, [this, person, row, person_table]()
            {
        QMessageBox::StandardButton reply = QMessageBox::question(nullptr, "Bestätigung", "Möchten Sie " + person->getFirstname() + " " + person->getSurname() + " wirklich löschen?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            person_table->removeRow(row);
            personList.removeOne(person);
        } });

    person_table->resizeColumnsToContents();
}

// Leeren der Input-Felder für das Hinzufügen eines Mediums
void MainWindow::abbrButtonClicked()
{
    QLineEdit *title_input = ui->title_input;
    QLineEdit *author_input = ui->author_input;
    QComboBox *type_input = ui->type_input;
    title_input->setText("");
    author_input->setText("");
    type_input->setCurrentIndex(0);
}

// Leeren der Input-Felder für das Hinzufügen einer Person
void MainWindow::abbrPersonButtonClicked()
{
    QLineEdit *firstname_input = this->findChild<QLineEdit *>("firstname_input");
    QLineEdit *surname_input = this->findChild<QLineEdit *>("surname_input");
    QDateEdit *birthday_input = this->findChild<QDateEdit *>("birthday_input");
    firstname_input->setText("");
    surname_input->setText("");
    birthday_input->setDate(QDate(2000, 1, 1));
}

// Drücken des "Medium hinzufügen" Buttons, Widgets dafür werden angezeigt
void MainWindow::addMediumButtonClicked()
{
    QPushButton *addButton = this->findChild<QPushButton *>("addmedia");
    QWidget *addMediaWidget = this->findChild<QWidget *>("add_media");
    QWidget *allMediaWidget = this->findChild<QWidget *>("all_media");
    QLabel *warning_media = ui->warning_media;
    QPushButton *search_media_btn = ui->search_media_btn;
    if (addMediaWidget->isVisible())
    {
        addButton->setText("Medium hinzufügen");
        allMediaWidget->setVisible(true);
        search_media_btn->setVisible(true);
        addMediaWidget->setVisible(false);
        warning_media->setVisible(false);
    }
    else
    {
        addButton->setText("Zurück");
        addMediaWidget->setVisible(true);
        allMediaWidget->setVisible(false);
        search_media_btn->setVisible(false);
    }
}

// Drücken des "Person hinzufügen" Buttons, Widgets dafür werden angezeigt
void MainWindow::addPersonButtonClicked()
{
    QPushButton *addPersonButton = this->findChild<QPushButton *>("addperson");
    QWidget *addPersonWidget = this->findChild<QWidget *>("add_person");
    QWidget *allPersonWidget = this->findChild<QWidget *>("all_person");
    QLabel *warning_person = ui->warning_person;
    QPushButton *search_person_btn = ui->search_person_btn;
    if (addPersonWidget->isVisible())
    {
        addPersonButton->setText("Person hinzufügen");
        allPersonWidget->setVisible(true);
        search_person_btn->setVisible(true);
        addPersonWidget->setVisible(false);
        warning_person->setVisible(false);
    }
    else
    {
        addPersonButton->setText("Zurück");
        addPersonWidget->setVisible(true);
        allPersonWidget->setVisible(false);
        search_person_btn->setVisible(false);
    }
}

// Drücken des "Medium suchen" Buttons, Widgets dafür werden angezeigt
void MainWindow::searchMediumButtonClicked()
{
    QPushButton *search_media_btn = ui->search_media_btn;
    QPushButton *addMedia = ui->addmedia;
    QWidget *addMediaWidget = ui->add_media;
    QWidget *search_media = ui->search_media;
    QLabel *warning_media = ui->warning_media;
    setupMediumTable();
    QTableWidget *media_table = ui->media_table;
    // Tabelle leeren und neu initialisieren
    media_table->clear();
    media_table->setRowCount(0);
    QStringList headers;
    headers << "Titel"
            << "Autor"
            << "Typ"
            << "Ausleiher"
            << ""
            << "";
    media_table->setHorizontalHeaderLabels(headers);

    if (search_media->isVisible())
    {
        search_media_btn->setText("Medium suchen");
        addMediaWidget->setVisible(false);
        search_media->setVisible(false);
        warning_media->setVisible(false);
        addMedia->setVisible(true);
        media_table->setRowCount(mediaList.size());
        for (int i = 0; i < mediaList.size(); ++i)
        {
            Medium *medium = mediaList.at(i);
            displayMedium(medium, i);
        }
    }
    else
    {
        search_media->setVisible(true);
        search_media_btn->setText("Zurück");
        addMedia->setVisible(false);
        addMediaWidget->setVisible(false);
    }
}

// Drücken des "Person suchen" Buttons, Widgets dafür werden angezeigt
void MainWindow::searchPersonButtonClicked()
{
    QPushButton *search_person_btn = ui->search_person_btn;
    QPushButton *addPerson = ui->addperson;
    QWidget *addPersonWidget = ui->add_person;
    QWidget *search_person = ui->search_person;
    QLabel *warning_person = ui->warning_person;
    QTableWidget *person_table = ui->person_table;
    // Tabelle leeren und neu initialisieren
    person_table->clear();
    person_table->setRowCount(0);
    QStringList headers;
    headers << "Vorname"
            << "Nachname"
            << "Geburtsdatum"
            << "Geschlecht"
            << "";
    person_table->setHorizontalHeaderLabels(headers);
    if (search_person->isVisible())
    {
        search_person_btn->setText("Person suchen");
        addPersonWidget->setVisible(false);
        search_person->setVisible(false);
        warning_person->setVisible(false);
        addPerson->setVisible(true);
        person_table->setRowCount(personList.size());
        for (int i = 0; i < personList.size(); ++i)
        {
            Person *person = personList.at(i);
            displayPerson(person, i);
        }
        person_table->show();
    }
    else
    {
        search_person->setVisible(true);
        search_person_btn->setText("Zurück");
        addPerson->setVisible(false);
        addPersonWidget->setVisible(false);
    }
}

// Sortieren der Medien nach Titel
void MainWindow::sortMedia()
{
    std::sort(mediaList.begin(), mediaList.end(), [](Medium *a, Medium *b)
              { return a->getTitle().compare(b->getTitle(), Qt::CaseInsensitive) < 0; });
}

// Sortieren der Personen nach Nachname
void MainWindow::sortPerson()
{
    std::sort(personList.begin(), personList.end(), [](Person *a, Person *b)
              { return a->getSurname().compare(b->getSurname(), Qt::CaseInsensitive) < 0; });
}

// Speichern der Daten in den Dateien beim Schließen des Programms
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
    saveMediaListToFile();
    savePersonListToFile();
}

// Speichern der Medien in die Datei "Medialist.txt"
void MainWindow::saveMediaListToFile()
{
    QFile file("Medialist.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        sortMedia();
        for (Medium *medium : mediaList)
        {
            out << medium->printMedium();
        }
        file.close();
    }
}

// Speichern der Personen in die Datei "Personlist.txt"
void MainWindow::savePersonListToFile()
{
    QFile file("Personlist.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        sortPerson();
        for (Person *person : personList)
        {
            out << person->printPerson();
        }
        file.close();
    }
}

// Laden der Medien aus der Datei "Medialist.txt"
void MainWindow::loadMediaListFromFile()
{
    QFile file("Medialist.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString title = in.readLine();
            QString author = in.readLine();
            int type = in.readLine().toInt();
            QString borrower = in.readLine();

            Medium *medium;
            if (type == 0)
                medium = new Book(title, author);
            else if (type == 1)
                medium = new CD(title, author);
            else if (type == 2)
                medium = new DVD(title, author);
            medium->setBorrower(borrower);
            mediaList.append(medium);
        }
        file.close();
    }
}

// Laden der Personen aus der Datei "Personlist.txt"
void MainWindow::loadPersonListFromFile()
{
    QFile file("Personlist.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString firstname = in.readLine();
            QString surname = in.readLine();
            QString birthdayStr = in.readLine();
            QDate birthday = QDate::fromString(birthdayStr, "dd.MM.yyyy");
            QChar gender = in.readLine().at(0);

            Person *person = new Person(firstname, surname, birthday, gender);
            personList.append(person);
        }
        file.close();
    }
}