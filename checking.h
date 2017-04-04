//checking.h
#pragma once
#include "mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QObject>
#include <QLabel>
#include<QLineEdit>



class Checking : public QWidget{
    // Q_OBJECT
public:
     Checking();
    ~Checking();
public slots:
      void updateCheckingBalance(double balance);
private:
    QLabel *title;
    QLabel *name;
    QLabel *cAccount;
    QTextEdit *ui;
    QTextEdit *fee;
};
