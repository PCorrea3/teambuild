#pragma once
#include"window.h"
#include<QLabel>
#include<QPushButton>
#include<QSpinBox>
#include<QComboBox>

class QPushButton;
class Transfer: public QWidget{
        Q_OBJECT
public:
    Transfer();
    ~Transfer();
signals:

public slots:
     void cancelButton();
private:
        QLabel *title;
        QPushButton *ok;
        QPushButton *cancel;
        QLabel *accTransferF;
        QLabel *accTransferT;
        QComboBox *transferF;
        QComboBox *transferT;
        QDoubleSpinBox *priceSpinBox;


};
