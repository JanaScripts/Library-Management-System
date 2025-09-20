#include "returnedbooks.h"
#include "ui_returnedbooks.h"
#include <QMessageBox>
#include <QVBoxLayout>  
#include <QScrollArea>  

returnedBooks::returnedBooks(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::returnedBooks)
{
    ui->setupUi(this);

    setWindowTitle("Recently Returned Books");

    connect(ui->pushButton, &QPushButton::clicked, this, &returnedBooks::pushBook);
    connect(ui->peekButton, &QPushButton::clicked, this, &returnedBooks::peekBook);

    connect(ui->viewStack, &QPushButton::clicked, this, &returnedBooks::viewStack); 
}

returnedBooks::~returnedBooks()
{
    delete ui;
}

void returnedBooks::pushBook()
{
    QString bookName = ui->bookNameLineEdit->text();  
    QString personName = ui->personNameLineEdit->text();  

    if (!bookName.isEmpty() && !personName.isEmpty()) {
        
        QPair<QString, QString> bookEntry(bookName, personName);
        bookStack.push(bookEntry);  

        ui->bookNameLineEdit->clear(); 
        ui->personNameLineEdit->clear();

        QMessageBox::information(this, "Book Returned", "Book successfully added.");
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter both book and name.");
    }
}

void returnedBooks::popBook()
{
    if (!bookStack.isEmpty()) {
        QPair<QString, QString> bookEntry = bookStack.pop();  
        QString bookName = bookEntry.first;
        QString personName = bookEntry.second;

        QMessageBox::information(this, "Successfully removed!\nBook Returned", "Book: " + bookName + "\nReturned by: " + personName);
    } else {
        QMessageBox::warning(this, "Stack Empty", "No recenty returned books.");
    }
}

void returnedBooks::peekBook()
{
    if (!bookStack.isEmpty()) {
        QPair<QString, QString> bookEntry = bookStack.top();  
        QString bookName = bookEntry.first;
        QString personName = bookEntry.second;

        QMessageBox::information(this, "Recently Returned Book", "The recently returned book is: " + bookName + "\nReturned by: " + personName);
    } else {
        QMessageBox::warning(this, "Stack Empty", "No recenty returned books.");
    }
}

void returnedBooks::viewStack()
{
    if (bookStack.isEmpty()) {
        QMessageBox::information(this, "Stack Empty", "No recenty returned books.");
        return;
    }

    QDialog* stackDialog = new QDialog(this);  
    stackDialog->setObjectName("stackDialog");  
    stackDialog->setWindowTitle("Returned Books Stack");
    stackDialog->setFixedSize(400, 300);  

    QScrollArea *scrollArea = new QScrollArea(stackDialog);
    scrollArea->setWidgetResizable(true);

    QWidget *stackWidget = new QWidget();
    QVBoxLayout *stackLayout = new QVBoxLayout(stackWidget);  

    int position = 1;

    for (const QPair<QString, QString> &bookEntry : bookStack) {
        QString bookText = QString("Entry Number: %1\nBook: %2\nReturned by: %3\n\n")
        .arg(position++)
            .arg(bookEntry.first)
            .arg(bookEntry.second);

        QLabel *label = new QLabel(bookText);
        label->setWordWrap(true);
        stackLayout->addWidget(label);  
    }

    stackWidget->setLayout(stackLayout);
    scrollArea->setWidget(stackWidget);

    QVBoxLayout *dialogLayout = new QVBoxLayout(stackDialog);
    dialogLayout->addWidget(scrollArea);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Yes | QDialogButtonBox::No);
    buttonBox->button(QDialogButtonBox::Yes)->setText("Remove Recently Returned Book");
    buttonBox->button(QDialogButtonBox::No)->setText("Close");
    dialogLayout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, [=]() {
        popBook();  
        stackDialog->close();  
    });

    connect(buttonBox, &QDialogButtonBox::rejected, stackDialog, &QDialog::reject);

    stackDialog->exec();
}
