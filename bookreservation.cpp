#include "bookreservation.h"
#include "ui_bookreservation.h"
#include <QMessageBox>
#include <QVBoxLayout>  
#include <QScrollArea>  

bookReservation::bookReservation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bookReservation)
{
    ui->setupUi(this);

    setWindowTitle("Book Reservation");

    connect(ui->enqueueButton, &QPushButton::clicked, this, &bookReservation::enqueueReservation);
    connect(ui->peekButton, &QPushButton::clicked, this, &bookReservation::peekReservation);
    connect(ui->viewQueue, &QPushButton::clicked, this, &bookReservation::viewQueue); 
}

bookReservation::~bookReservation()
{
    delete ui;
}

void bookReservation::enqueueReservation()
{
    QString name = ui->nameInput->text();
    QString book = ui->bookInput->text();

    if (name.isEmpty() || book.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both name and book.");
        return;
    }

    QString reservationDetails = QString("Name: %1\nBook Reserved: %2").arg(name).arg(book);
    reservationQueue.enqueue(reservationDetails);

    ui->nameInput->clear();
    ui->bookInput->clear();

    QMessageBox::information(this, "Reservation Success", "Book successfully reserved.");
}

void bookReservation::dequeueReservation()
{
    if (reservationQueue.isEmpty()) {
        QMessageBox::information(this, "Queue Empty", "No reservations to dequeue.");
        return;
    }

    reservationQueue.dequeue();  

    QMessageBox::information(this, "Success", "Reservation successfully dequeued.");

    QDialog* queueDialog = this->findChild<QDialog*>("queueDialog");
    if (queueDialog) {
        queueDialog->close();  
    }

    QWidget* parentWidget = this->parentWidget();
    if (parentWidget) {
        parentWidget->show(); 
    }
}

void bookReservation::peekReservation()
{
    if (reservationQueue.isEmpty()) {
        QMessageBox::information(this, "Queue Empty", "No current book reservations.");
        return;
    }

    QString nextReservation = QString("Queue Number: 1\n%1").arg(reservationQueue.head());
    QMessageBox::information(this, "Reservation", nextReservation);
}

void bookReservation::viewQueue()
{
    if (reservationQueue.isEmpty()) {
        QMessageBox::information(this, "Queue Empty", "No current book reservations.");
        return;
    }

    QDialog* queueDialog = new QDialog(this);  
    queueDialog->setObjectName("queueDialog");  
    queueDialog->setWindowTitle("Current Queue");
    queueDialog->setFixedSize(400, 300);  

    QScrollArea *scrollArea = new QScrollArea(queueDialog);
    scrollArea->setWidgetResizable(true);

    QWidget *queueWidget = new QWidget();
    QVBoxLayout *queueLayout = new QVBoxLayout(queueWidget);  

    int position = 1;
    foreach (const QString &reservation, reservationQueue) {
        QString reservationText = QString("Queue Number: %1\n%2\n\n").arg(position++).arg(reservation);
        QLabel *label = new QLabel(reservationText);
        label->setWordWrap(true);
        queueLayout->addWidget(label);
    }
    queueWidget->setLayout(queueLayout);

    scrollArea->setWidget(queueWidget);

    QVBoxLayout *dialogLayout = new QVBoxLayout(queueDialog);
    dialogLayout->addWidget(scrollArea);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Yes | QDialogButtonBox::No);
    buttonBox->button(QDialogButtonBox::Yes)->setText("Dequeue Reservation");
    buttonBox->button(QDialogButtonBox::No)->setText("Close");
    dialogLayout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, [=]() {
        dequeueReservation();  
        queueDialog->close();  
    });

    connect(buttonBox, &QDialogButtonBox::rejected, queueDialog, &QDialog::reject);

    queueDialog->exec();
}

