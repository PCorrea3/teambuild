//MainWindow.h
#pragma once

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
 signals:

 public slots:
      void showSavings();
      void showCheckings();
      void showTransfer();
private:
     QPushButton *button1;
     QPushButton *button2;
     QPushButton *button3;
     QPushButton *button4;
};
