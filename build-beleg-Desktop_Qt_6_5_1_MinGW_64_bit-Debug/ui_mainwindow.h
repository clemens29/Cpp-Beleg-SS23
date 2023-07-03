/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *Medien;
    QVBoxLayout *verticalLayout_8;
    QPushButton *addmedia;
    QPushButton *search_media_btn;
    QWidget *add_media;
    QVBoxLayout *verticalLayout_2;
    QLabel *warning_media;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *title_input;
    QLabel *label_2;
    QLineEdit *author_input;
    QLabel *label_3;
    QComboBox *type_input;
    QFormLayout *formLayout_2;
    QDialogButtonBox *saveBox_media;
    QWidget *search_media;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QFormLayout *formLayout_6;
    QLabel *label_11;
    QLineEdit *title_input_search;
    QLabel *label_12;
    QLineEdit *author_input_search;
    QFormLayout *formLayout_7;
    QDialogButtonBox *searchBox_media;
    QWidget *all_media;
    QVBoxLayout *verticalLayout;
    QTableWidget *media_table;
    QWidget *Personen;
    QVBoxLayout *verticalLayout_9;
    QPushButton *addperson;
    QPushButton *search_person_btn;
    QWidget *add_person;
    QVBoxLayout *verticalLayout_6;
    QLabel *warning_person;
    QFormLayout *formLayout_3;
    QLabel *label_4;
    QLineEdit *firstname_input;
    QLabel *label_5;
    QLineEdit *surname_input;
    QLabel *label_6;
    QDateEdit *birthday_input;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *gender_input_w;
    QRadioButton *gender_input_m;
    QRadioButton *gender_input_d;
    QDialogButtonBox *saveBox_person;
    QWidget *all_person;
    QVBoxLayout *verticalLayout_5;
    QWidget *search_person;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_13;
    QFormLayout *formLayout_4;
    QLabel *label_9;
    QLineEdit *firstname_input_search;
    QLabel *label_10;
    QLineEdit *surname_input_search;
    QHBoxLayout *horizontalLayout_3;
    QDialogButtonBox *searchBox_person;
    QTableWidget *person_table;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        Medien = new QWidget();
        Medien->setObjectName("Medien");
        verticalLayout_8 = new QVBoxLayout(Medien);
        verticalLayout_8->setObjectName("verticalLayout_8");
        addmedia = new QPushButton(Medien);
        addmedia->setObjectName("addmedia");

        verticalLayout_8->addWidget(addmedia);

        search_media_btn = new QPushButton(Medien);
        search_media_btn->setObjectName("search_media_btn");

        verticalLayout_8->addWidget(search_media_btn);

        add_media = new QWidget(Medien);
        add_media->setObjectName("add_media");
        add_media->setEnabled(true);
        verticalLayout_2 = new QVBoxLayout(add_media);
        verticalLayout_2->setObjectName("verticalLayout_2");
        warning_media = new QLabel(add_media);
        warning_media->setObjectName("warning_media");
        warning_media->setMaximumSize(QSize(16777215, 18));
        warning_media->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(warning_media);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(add_media);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        title_input = new QLineEdit(add_media);
        title_input->setObjectName("title_input");

        formLayout->setWidget(0, QFormLayout::FieldRole, title_input);

        label_2 = new QLabel(add_media);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        author_input = new QLineEdit(add_media);
        author_input->setObjectName("author_input");

        formLayout->setWidget(1, QFormLayout::FieldRole, author_input);

        label_3 = new QLabel(add_media);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        type_input = new QComboBox(add_media);
        type_input->addItem(QString());
        type_input->addItem(QString());
        type_input->addItem(QString());
        type_input->setObjectName("type_input");

        formLayout->setWidget(3, QFormLayout::FieldRole, type_input);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        saveBox_media = new QDialogButtonBox(add_media);
        saveBox_media->setObjectName("saveBox_media");
        saveBox_media->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, saveBox_media);


        formLayout->setLayout(4, QFormLayout::FieldRole, formLayout_2);


        verticalLayout_2->addLayout(formLayout);


        verticalLayout_8->addWidget(add_media);

        search_media = new QWidget(Medien);
        search_media->setObjectName("search_media");
        search_media->setEnabled(true);
        verticalLayout_3 = new QVBoxLayout(search_media);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_8 = new QLabel(search_media);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 18));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName("formLayout_6");
        label_11 = new QLabel(search_media);
        label_11->setObjectName("label_11");

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_11);

        title_input_search = new QLineEdit(search_media);
        title_input_search->setObjectName("title_input_search");

        formLayout_6->setWidget(0, QFormLayout::FieldRole, title_input_search);

        label_12 = new QLabel(search_media);
        label_12->setObjectName("label_12");

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_12);

        author_input_search = new QLineEdit(search_media);
        author_input_search->setObjectName("author_input_search");

        formLayout_6->setWidget(1, QFormLayout::FieldRole, author_input_search);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName("formLayout_7");
        searchBox_media = new QDialogButtonBox(search_media);
        searchBox_media->setObjectName("searchBox_media");
        searchBox_media->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, searchBox_media);


        formLayout_6->setLayout(3, QFormLayout::FieldRole, formLayout_7);


        verticalLayout_3->addLayout(formLayout_6);


        verticalLayout_8->addWidget(search_media);

        all_media = new QWidget(Medien);
        all_media->setObjectName("all_media");
        verticalLayout = new QVBoxLayout(all_media);
        verticalLayout->setObjectName("verticalLayout");
        media_table = new QTableWidget(all_media);
        media_table->setObjectName("media_table");

        verticalLayout->addWidget(media_table);


        verticalLayout_8->addWidget(all_media);

        tabWidget->addTab(Medien, QString());
        Personen = new QWidget();
        Personen->setObjectName("Personen");
        verticalLayout_9 = new QVBoxLayout(Personen);
        verticalLayout_9->setObjectName("verticalLayout_9");
        addperson = new QPushButton(Personen);
        addperson->setObjectName("addperson");

        verticalLayout_9->addWidget(addperson);

        search_person_btn = new QPushButton(Personen);
        search_person_btn->setObjectName("search_person_btn");

        verticalLayout_9->addWidget(search_person_btn);

        add_person = new QWidget(Personen);
        add_person->setObjectName("add_person");
        verticalLayout_6 = new QVBoxLayout(add_person);
        verticalLayout_6->setObjectName("verticalLayout_6");
        warning_person = new QLabel(add_person);
        warning_person->setObjectName("warning_person");
        warning_person->setMaximumSize(QSize(16777215, 18));

        verticalLayout_6->addWidget(warning_person);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_4 = new QLabel(add_person);
        label_4->setObjectName("label_4");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_4);

        firstname_input = new QLineEdit(add_person);
        firstname_input->setObjectName("firstname_input");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, firstname_input);

        label_5 = new QLabel(add_person);
        label_5->setObjectName("label_5");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_5);

        surname_input = new QLineEdit(add_person);
        surname_input->setObjectName("surname_input");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, surname_input);

        label_6 = new QLabel(add_person);
        label_6->setObjectName("label_6");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_6);

        birthday_input = new QDateEdit(add_person);
        birthday_input->setObjectName("birthday_input");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, birthday_input);

        label_7 = new QLabel(add_person);
        label_7->setObjectName("label_7");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gender_input_w = new QRadioButton(add_person);
        gender_input_w->setObjectName("gender_input_w");

        horizontalLayout_2->addWidget(gender_input_w);

        gender_input_m = new QRadioButton(add_person);
        gender_input_m->setObjectName("gender_input_m");

        horizontalLayout_2->addWidget(gender_input_m);

        gender_input_d = new QRadioButton(add_person);
        gender_input_d->setObjectName("gender_input_d");

        horizontalLayout_2->addWidget(gender_input_d);


        formLayout_3->setLayout(3, QFormLayout::FieldRole, horizontalLayout_2);

        saveBox_person = new QDialogButtonBox(add_person);
        saveBox_person->setObjectName("saveBox_person");
        saveBox_person->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, saveBox_person);


        verticalLayout_6->addLayout(formLayout_3);


        verticalLayout_9->addWidget(add_person);

        all_person = new QWidget(Personen);
        all_person->setObjectName("all_person");
        verticalLayout_5 = new QVBoxLayout(all_person);
        verticalLayout_5->setObjectName("verticalLayout_5");
        search_person = new QWidget(all_person);
        search_person->setObjectName("search_person");
        search_person->setMinimumSize(QSize(30, 30));
        verticalLayout_4 = new QVBoxLayout(search_person);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_13 = new QLabel(search_person);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_13);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_9 = new QLabel(search_person);
        label_9->setObjectName("label_9");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_9);

        firstname_input_search = new QLineEdit(search_person);
        firstname_input_search->setObjectName("firstname_input_search");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, firstname_input_search);

        label_10 = new QLabel(search_person);
        label_10->setObjectName("label_10");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_10);

        surname_input_search = new QLineEdit(search_person);
        surname_input_search->setObjectName("surname_input_search");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, surname_input_search);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        formLayout_4->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        searchBox_person = new QDialogButtonBox(search_person);
        searchBox_person->setObjectName("searchBox_person");
        searchBox_person->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, searchBox_person);


        verticalLayout_4->addLayout(formLayout_4);


        verticalLayout_5->addWidget(search_person);

        person_table = new QTableWidget(all_person);
        person_table->setObjectName("person_table");

        verticalLayout_5->addWidget(person_table);


        verticalLayout_9->addWidget(all_person);

        tabWidget->addTab(Personen, QString());

        verticalLayout_7->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addmedia->setText(QCoreApplication::translate("MainWindow", "Medium hinzuf\303\274gen", nullptr));
        search_media_btn->setText(QCoreApplication::translate("MainWindow", "Medium suchen", nullptr));
        warning_media->setText(QCoreApplication::translate("MainWindow", "Titel muss ausgef\303\274llt sein!", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Titel:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Autor/Interpret:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Medienart: ", nullptr));
        type_input->setItemText(0, QCoreApplication::translate("MainWindow", "Buch", nullptr));
        type_input->setItemText(1, QCoreApplication::translate("MainWindow", "CD", nullptr));
        type_input->setItemText(2, QCoreApplication::translate("MainWindow", "DVD", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Suche", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Titel:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Autor/Interpret:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Medien), QCoreApplication::translate("MainWindow", "Medien", nullptr));
        addperson->setText(QCoreApplication::translate("MainWindow", "Person hinzuf\303\274gen", nullptr));
        search_person_btn->setText(QCoreApplication::translate("MainWindow", "Person suchen", nullptr));
        warning_person->setText(QCoreApplication::translate("MainWindow", "Vor- und Nachname muss ausgef\303\274llt werden!", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Vorname:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nachname:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Geburtstag:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Geschlecht:", nullptr));
        gender_input_w->setText(QCoreApplication::translate("MainWindow", "weiblich", nullptr));
        gender_input_m->setText(QCoreApplication::translate("MainWindow", "m\303\244nnlich", nullptr));
        gender_input_d->setText(QCoreApplication::translate("MainWindow", "divers", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Suche", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Vorname:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Nachname:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Personen), QCoreApplication::translate("MainWindow", "Personen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
