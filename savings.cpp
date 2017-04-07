//savings.cpp
#include "savings.h"

Savings::Savings() {
    setFixedSize(240, 160);

    title = new QLabel("Savings Account");
    name = new QLabel("Hello, John");
    sAccount = new QLabel("Account# 54321");

    QFont font = title->font();
    font.setPointSize(14);
    QFont font2 = name->font();
    font2.setPointSize(12);

    title->setFont(font);
    name->setFont(font2);
    sAccount->setFont(font2);

    savingsAcct = new QLineEdit(this);
    savingsAcct->setText(QString::number(0,'F',2));
    savingsAcct->setReadOnly(true);

    interest = new QLineEdit(this);
    interest->setText("Interest: 0.2%");
    interest->setReadOnly(true);

    QGridLayout *layout = new QGridLayout();

    layout->setColumnStretch(1,1);
    layout->addWidget(title,0,0);
    layout->addWidget(name,1,0);
    layout->addWidget(sAccount,2,0);
    sAccount->setMaximumSize(180,40);
    layout->addWidget(savingsAcct,3,0);
    layout->addWidget(interest, 4, 0);

    setLayout(layout);
	setVisible(false);
}

Savings::~Savings() {}

void Savings::updateSavingsBalance(double amt) {
	savingsAcct->setText(QString::number(amt, 'F', 2));
}
