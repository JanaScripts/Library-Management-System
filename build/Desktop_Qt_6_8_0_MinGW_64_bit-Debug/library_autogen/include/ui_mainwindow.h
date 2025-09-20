/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *openReturnedBooksButton;
    QPushButton *openBookReservationButton;
    QLabel *libraryLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(689, 411);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        openReturnedBooksButton = new QPushButton(centralwidget);
        openReturnedBooksButton->setObjectName("openReturnedBooksButton");
        openReturnedBooksButton->setGeometry(QRect(220, 150, 221, 51));
        QFont font;
        font.setPointSize(11);
        openReturnedBooksButton->setFont(font);
        openBookReservationButton = new QPushButton(centralwidget);
        openBookReservationButton->setObjectName("openBookReservationButton");
        openBookReservationButton->setGeometry(QRect(220, 230, 221, 51));
        openBookReservationButton->setFont(font);
        libraryLabel = new QLabel(centralwidget);
        libraryLabel->setObjectName("libraryLabel");
        libraryLabel->setGeometry(QRect(0, 40, 691, 71));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        libraryLabel->setFont(font1);
        libraryLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 689, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openReturnedBooksButton->setText(QCoreApplication::translate("MainWindow", "Recently Returned Books", nullptr));
        openBookReservationButton->setText(QCoreApplication::translate("MainWindow", "Book Reservation", nullptr));
        libraryLabel->setText(QCoreApplication::translate("MainWindow", "LIBRARY MANAGEMENT SYSTEM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
