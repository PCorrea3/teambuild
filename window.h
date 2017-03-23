// Window.h
#pragma once

#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QLineEdit>

class QPushButton;

class Window : public QWidget {
Q_OBJECT
public:
     Window(QWidget *parent = 0);
     ~Window();
signals:

public slots:
     void showWindow();
private:
     QPushButton *submit;
     QLineEdit *ui;
     QLineEdit *ui2;
};
