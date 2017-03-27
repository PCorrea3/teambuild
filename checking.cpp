//checking.cpp
#include "savings.h"
#include "mainwindow.h"
#include "window.h"
#include "checking.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QTextEdit>
#include <QFont>

Checking::Checking() {
    setFixedSize(240, 160);

    title = new QLabel("Checking Account");
    name = new QLabel("Hello, John");
    cAccount = new QLabel("Account# 12345");

    QFont font = title->font();
    font.setPointSize(14);
    QFont font2 = name->font();
    font2.setPointSize(12);

    title->setFont(font);
    name->setFont(font2);
    cAccount->setFont(font2);

    money = new QTextEdit(this);
    money->insertPlainText("Available: $1,234,567.89");
    money->setReadOnly(true);   

    fee = new QTextEdit(this);
    fee->insertPlainText("Overdraft fee: $35.00");
    fee->setReadOnly(true);

    QGridLayout *layout = new QGridLayout();

    layout->setColumnStretch(1,1);
    layout->addWidget(title, 0, 0);
    layout->addWidget(name, 1, 0);
    name->setMaximumSize(140,30);
    layout->addWidget(cAccount, 2, 0);
    cAccount->setMaximumSize(180,40);
    layout->addWidget(money, 3, 0);
    layout->addWidget(fee, 4, 0);

    setLayout(layout);
}

Checking::~Checking() {}
