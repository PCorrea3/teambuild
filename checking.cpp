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

	ui = new QLineEdit(this);
	ui->setText(QString::number(0, 'F', 2));
	ui->setReadOnly(true);

	fee = new QLineEdit(this);
	fee->setText("Overdraft fee: $35.00");
	fee->setReadOnly(true);

	QGridLayout *layout = new QGridLayout();

	layout->setColumnStretch(1, 1);
	layout->addWidget(title, 0, 0);
	layout->addWidget(name, 1, 0);
	name->setMaximumSize(140, 30);
	layout->addWidget(cAccount, 2, 0);
	cAccount->setMaximumSize(180, 40);
	layout->addWidget(ui, 3, 0);
	layout->addWidget(fee, 4, 0);

	setLayout(layout);
	setVisible(false);
}

Checking::~Checking() {}

void Checking::updateCheckingBalance(double balance) {
	ui->setText(QString::number(balance, 'F', 2));
}
