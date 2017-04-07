//checking.h
#pragma once
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QObject>
#include <QLabel>
#include<QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFont>



class Checking : public QWidget{
    // Q_OBJECT
public:
     Checking();
    ~Checking();
	void updateCheckingBalance(double balance);

private:
    QLabel *title;
    QLabel *name;
    QLabel *cAccount;
    QLineEdit *checkingAcct;
    QLineEdit *fee;
};
