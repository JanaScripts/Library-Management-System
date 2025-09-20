/********************************************************************************
** Form generated from reading UI file 'returnedbooks.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURNEDBOOKS_H
#define UI_RETURNEDBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_returnedBooks
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *personNameLineEdit;
    QLineEdit *bookNameLineEdit;
    QPushButton *pushButton;
    QPushButton *peekButton;
    QLabel *nameLabel;
    QLabel *bookLabel;
    QLabel *bookReservationLabel;
    QPushButton *viewStack;

    void setupUi(QDialog *returnedBooks)
    {
        if (returnedBooks->objectName().isEmpty())
            returnedBooks->setObjectName("returnedBooks");
        returnedBooks->resize(580, 350);
        buttonBox = new QDialogButtonBox(returnedBooks);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(204, 290, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        buttonBox->setCenterButtons(true);
        personNameLineEdit = new QLineEdit(returnedBooks);
        personNameLineEdit->setObjectName("personNameLineEdit");
        personNameLineEdit->setGeometry(QRect(240, 100, 241, 31));
        QFont font;
        font.setPointSize(11);
        personNameLineEdit->setFont(font);
        bookNameLineEdit = new QLineEdit(returnedBooks);
        bookNameLineEdit->setObjectName("bookNameLineEdit");
        bookNameLineEdit->setGeometry(QRect(240, 150, 241, 31));
        bookNameLineEdit->setFont(font);
        pushButton = new QPushButton(returnedBooks);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 230, 150, 28));
        pushButton->setFont(font);
        peekButton = new QPushButton(returnedBooks);
        peekButton->setObjectName("peekButton");
        peekButton->setGeometry(QRect(210, 230, 150, 28));
        peekButton->setFont(font);
        nameLabel = new QLabel(returnedBooks);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(80, 110, 131, 16));
        nameLabel->setFont(font);
        bookLabel = new QLabel(returnedBooks);
        bookLabel->setObjectName("bookLabel");
        bookLabel->setGeometry(QRect(80, 160, 151, 16));
        bookLabel->setFont(font);
        bookReservationLabel = new QLabel(returnedBooks);
        bookReservationLabel->setObjectName("bookReservationLabel");
        bookReservationLabel->setGeometry(QRect(0, 10, 581, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font1.setPointSize(27);
        font1.setBold(true);
        bookReservationLabel->setFont(font1);
        bookReservationLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        viewStack = new QPushButton(returnedBooks);
        viewStack->setObjectName("viewStack");
        viewStack->setGeometry(QRect(380, 230, 150, 28));
        viewStack->setFont(font);

        retranslateUi(returnedBooks);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, returnedBooks, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, returnedBooks, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(returnedBooks);
    } // setupUi

    void retranslateUi(QDialog *returnedBooks)
    {
        returnedBooks->setWindowTitle(QCoreApplication::translate("returnedBooks", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("returnedBooks", "Add Book", nullptr));
        peekButton->setText(QCoreApplication::translate("returnedBooks", "Show Latest Book", nullptr));
        nameLabel->setText(QCoreApplication::translate("returnedBooks", "Enter the name:", nullptr));
        bookLabel->setText(QCoreApplication::translate("returnedBooks", "Enter the book title:", nullptr));
        bookReservationLabel->setText(QCoreApplication::translate("returnedBooks", "RETURNED BOOKS", nullptr));
        viewStack->setText(QCoreApplication::translate("returnedBooks", "Show All Books", nullptr));
    } // retranslateUi

};

namespace Ui {
    class returnedBooks: public Ui_returnedBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURNEDBOOKS_H
