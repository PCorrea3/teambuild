//MainWindow.h
#pragma once
#include "savings.h"
#include "checking.h"
#include "transfer.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QTextEdit>
#include <QFont>
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QObject>

class QPushButton;

class MainWindow : public QWidget {
    Q_OBJECT
 public:
      MainWindow(QWidget *parent = 0);
      ~MainWindow();
      double debtChecking(double amt);
      double debtSavings(double amt);
      double checking = 300.00;
      double savings = 200.00;
 signals:
      void onCheckingBalanceChange(double);
      void onSavingsBalanceChange(double);
 public slots:
      void showSavings();
      void showCheckings();
      void showTransfer();
      void transferFunds();
      //void updateSavingsBalance(double balance);
private:
     QPushButton *button1;
     QPushButton *button2;
     QPushButton *button3;
     QPushButton *button4;
     Checking* checkingAcc = new Checking();
     Transfer* transWindow = new Transfer();
     QLineEdit *ui = new QLineEdit();
     QLineEdit *ui2 = new QLineEdit();
};
