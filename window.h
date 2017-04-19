// Window.h
#pragma once

#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QFont>
#include<QLabel>
#include<QString>


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
     QLabel *usernameLabel;
     QLabel *passwordLabel;
     QLineEdit *username;
     QLineEdit *password;
     QString str = "";
     QString str2 = "";

};
