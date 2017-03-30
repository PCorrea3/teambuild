#pragma once
#include"window.h"
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QComboBox>
#include<QDebug>
#include <QString>
#include <QGridLayout>
#include <QFont>
#include <QDoubleValidator>

class QPushButton;
class Transfer: public QWidget{
        Q_OBJECT
public:
    Transfer();
    ~Transfer();
    enum AccountType{NONE, CHECKING, SAVINGS};
    double getTextAmt();
    Transfer::AccountType getSelected();
    QPushButton *getTransferButton();
signals:

public slots:
     void cancelButton();
     void dropDownChange(int index);
private:
        QLabel *title;
        QPushButton *transferButton;
        QPushButton *cancel;
        QLabel *accTransferF;
        QLabel *accTransferT;
        QComboBox *transferF;
        QComboBox *transferT;
        QLineEdit* transferBox = new QLineEdit(this);
        AccountType selected = NONE;
};
