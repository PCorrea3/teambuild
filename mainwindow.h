//MainWindow.h
#pragma once

#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QTextEdit>
#include "transfer.h"
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

 public slots:
      void showSavings();
      void showCheckings();
      void showTransfer();
      void transferFunds();
private:
     QPushButton *button1;
     QPushButton *button2;
     QPushButton *button3;
     QPushButton *button4;
     Transfer* transWindow = new Transfer();
     QLineEdit *ui = new QLineEdit();
     QLineEdit *ui2 = new QLineEdit();
};
