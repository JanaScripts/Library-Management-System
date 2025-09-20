#ifndef BOOKRESERVATION_H
#define BOOKRESERVATION_H

#include <QDialog>
#include <QString>
#include <QQueue>
#include <QPushButton>
#include <QLabel>
#include <QDialogButtonBox>
#include <QScrollArea>
#include <QVBoxLayout>

namespace Ui {
class bookReservation;
}

class bookReservation : public QDialog
{
    Q_OBJECT

public:
    explicit bookReservation(QWidget *parent = nullptr);
    ~bookReservation();

private slots:
    void enqueueReservation();
    void dequeueReservation();
    void peekReservation();
    void viewQueue();

private:
    Ui::bookReservation *ui;
    QQueue<QString> reservationQueue;
};

#endif
