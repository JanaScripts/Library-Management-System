#ifndef RETURNEDBOOKS_H
#define RETURNEDBOOKS_H

#include <QDialog>
#include <QStack>
#include <QPair>

namespace Ui {
class returnedBooks;
}

class returnedBooks : public QDialog
{
    Q_OBJECT

public:
    explicit returnedBooks(QWidget *parent = nullptr);
    ~returnedBooks();

private slots:
    void pushBook();
    void popBook();
    void peekBook();
    void viewStack();

private:
    Ui::returnedBooks *ui;

    QStack<QPair<QString, QString>> bookStack;

    void updateStackDisplay();
};

#endif
