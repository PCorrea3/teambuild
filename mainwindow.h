//MainWindow.h
#pragma once
#include "savings.h"
#include "checking.h"
#include "transfer.h"
#include "window.h"
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

	  public slots:
      void showSavings();
      void showCheckings();
      void showTransfer();
      void transferFunds();



private:
     QPushButton *savingsButton;
     QPushButton *checkingButton;
     QPushButton *transferButton;
     QPushButton *historyButton;
     Checking* checkingAcc = new Checking();
	 Savings* savingsAcc = new Savings();
	 Transfer* transWindow = new Transfer();
     QLineEdit *checkingAmt = new QLineEdit();
     QLineEdit *savingsAmt = new QLineEdit();
};
