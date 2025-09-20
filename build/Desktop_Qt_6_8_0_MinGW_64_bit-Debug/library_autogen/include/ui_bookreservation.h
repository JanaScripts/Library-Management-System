/********************************************************************************
** Form generated from reading UI file 'bookreservation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKRESERVATION_H
#define UI_BOOKRESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_bookReservation
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *nameLabel;
    QLabel *bookLabel;
    QLineEdit *nameInput;
    QLineEdit *bookInput;
    QPushButton *enqueueButton;
    QPushButton *peekButton;
    QLabel *bookReservationLabel;
    QPushButton *viewQueue;

    void setupUi(QDialog *bookReservation)
    {
        if (bookReservation->objectName().isEmpty())
            bookReservation->setObjectName("bookReservation");
        bookReservation->resize(580, 350);
        bookReservation->setMaximumSize(QSize(668, 16777215));
        buttonBox = new QDialogButtonBox(bookReservation);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(204, 290, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        buttonBox->setCenterButtons(true);
        nameLabel = new QLabel(bookReservation);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(80, 110, 131, 16));
        QFont font;
        font.setPointSize(11);
        nameLabel->setFont(font);
        bookLabel = new QLabel(bookReservation);
        bookLabel->setObjectName("bookLabel");
        bookLabel->setGeometry(QRect(80, 160, 151, 16));
        bookLabel->setFont(font);
        nameInput = new QLineEdit(bookReservation);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(240, 100, 241, 31));
        nameInput->setFont(font);
        bookInput = new QLineEdit(bookReservation);
        bookInput->setObjectName("bookInput");
        bookInput->setGeometry(QRect(240, 150, 241, 31));
        bookInput->setFont(font);
        enqueueButton = new QPushButton(bookReservation);
        enqueueButton->setObjectName("enqueueButton");
        enqueueButton->setGeometry(QRect(40, 230, 150, 28));
        enqueueButton->setFont(font);
        peekButton = new QPushButton(bookReservation);
        peekButton->setObjectName("peekButton");
        peekButton->setGeometry(QRect(210, 230, 150, 28));
        peekButton->setFont(font);
        bookReservationLabel = new QLabel(bookReservation);
        bookReservationLabel->setObjectName("bookReservationLabel");
        bookReservationLabel->setGeometry(QRect(0, 10, 581, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font1.setPointSize(27);
        font1.setBold(true);
        bookReservationLabel->setFont(font1);
        bookReservationLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        viewQueue = new QPushButton(bookReservation);
        viewQueue->setObjectName("viewQueue");
        viewQueue->setGeometry(QRect(380, 230, 150, 28));
        viewQueue->setFont(font);

        retranslateUi(bookReservation);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, bookReservation, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, bookReservation, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(bookReservation);
    } // setupUi

    void retranslateUi(QDialog *bookReservation)
    {
        bookReservation->setWindowTitle(QCoreApplication::translate("bookReservation", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("bookReservation", "Enter the name:", nullptr));
        bookLabel->setText(QCoreApplication::translate("bookReservation", "Enter the book title:", nullptr));
        enqueueButton->setText(QCoreApplication::translate("bookReservation", "Add Reservation", nullptr));
        peekButton->setText(QCoreApplication::translate("bookReservation", "Show First in Queue", nullptr));
        bookReservationLabel->setText(QCoreApplication::translate("bookReservation", "BOOK RESERVATION", nullptr));
        viewQueue->setText(QCoreApplication::translate("bookReservation", "Show Queue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookReservation: public Ui_bookReservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKRESERVATION_H
