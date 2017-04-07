// savings.h
#pragma once

#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QFont>
#include <QLineEdit>

class Savings : public QWidget {
public:
    Savings();
    ~Savings();
	void updateSavingsBalance(double amt);
private:
    QLabel *title;
    QLabel *name;
    QLabel *sAccount;
    QLineEdit *savingsAcct;
    QLineEdit *interest;
};
