#pragma once
#include"window.h"
#include<QLabel>
#include<QPushButton>
#include<QSpinBox>
#include<QComboBox>
#include<QDebug>

class QPushButton;
class Transfer: public QWidget{
        Q_OBJECT
public:
    Transfer();
    ~Transfer();
    enum AccountType{NONE, CHECKING, SAVINGS};
signals:

public slots:
     void cancelButton();
     void dropDownChange(int index);
private:
        QLabel *title;
        QPushButton *ok;
        QPushButton *cancel;
        QLabel *accTransferF;
        QLabel *accTransferT;
        QComboBox *transferF;
        QComboBox *transferT;
        QDoubleSpinBox *priceSpinBox;
        AccountType selected = NONE;
};
