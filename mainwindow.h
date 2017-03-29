//MainWindow.h
#pragma once

#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include<QTextEdit>

class QPushButton;

class MainWindow : public QWidget {
    Q_OBJECT
 public:
      MainWindow(QWidget *parent = 0);
      ~MainWindow();
      double debtChecking(double amt);
      double debtSavings(double amt);

 signals:

 public slots:
      void showSavings();
      void showCheckings();
      void showTransfer();
      void transferChecking();
      void transferSavings();
private:
      double checking = 0.00;
      double savings = 0.00;

     QPushButton *button1;
     QPushButton *button2;
     QPushButton *button3;
     QPushButton *button4;


};
