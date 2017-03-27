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

 signals:

 public slots:
      void showSavings();
      void showCheckings();
      void showTransfer();
private:
      double checkings = 12345.67;
      double savings = 0.07;

     QPushButton *button1;
     QPushButton *button2;
     QPushButton *button3;
     QPushButton *button4;


};
