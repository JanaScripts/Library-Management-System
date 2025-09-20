#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bookreservation.h"  
#include "returnedbooks.h"   
#include <QLabel>  

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Library Managemen System");

    connect(ui->openBookReservationButton, &QPushButton::clicked, this, &MainWindow::openBookReservation);

    connect(ui->openReturnedBooksButton, &QPushButton::clicked, this, &MainWindow::openReturnedBooks);

    ui->libraryLabel->setAlignment(Qt::AlignCenter); 
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openBookReservation()
{
    bookReservation *reservationDialog = new bookReservation(this);  
    reservationDialog->exec();  
}

void MainWindow::openReturnedBooks()
{
    returnedBooks *returnedBooksDialog = new returnedBooks(this); 
    returnedBooksDialog->exec();  
}
