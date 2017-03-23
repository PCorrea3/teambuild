#pragma once
#include"window.h"
#include<QLabel>
#include<QPushButton>

class QPushButton;
class Transfer: public QWidget{
        Q_OBJECT
public:
    Transfer();
    ~Transfer();
private:
        QLabel *title;
        QPushButton *ok;
        QPushButton *cancel;

};
