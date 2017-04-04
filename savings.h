// savings.h
#pragma once

#include "window.h"
#include "mainwindow.h"
#include <QLabel>
#include <QTextEdit>


class Savings : public QWidget {
public:
    Savings();
    ~Savings();
private:
    QLabel *title;
    QLabel *name;
    QLabel *sAccount;
    QTextEdit *savingsAcct;
    QTextEdit *interest;
};
