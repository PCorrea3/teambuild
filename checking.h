//savings.h
#pragma once
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QObject>
#include <QLabel>

class QPushButton;
class Checking : public QWidget {
    Q_OBJECT
public:
     Checking();
    ~Checking();
private:
    QLabel *title;
    QLabel *name;
    QLabel *cAccount;
    QTextEdit *money;
    QTextEdit *fee;
};
