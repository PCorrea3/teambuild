// MainWindow.cpp
#include "window.h"
#include "mainwindow.h"
#include "savings.h"
#include "checking.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QTextEdit>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(420, 320);

    button1 = new QPushButton("Savings Account");
    button2 = new QPushButton("Checking Account");
    button3 = new QPushButton("Transfer Funds");
    button4 = new QPushButton("Transaction History");

    QTextEdit *ui = new QTextEdit(this);
    ui->insertPlainText("Savings: $0.07");\
    ui->setReadOnly(true);

    QTextEdit *ui2 = new QTextEdit(this);
    ui2->insertPlainText("Available: $1,234,567.89");
    ui2->setReadOnly(true);

    QLabel* label=new QLabel("Bank Application");
    QFont font = label->font();
    font.setPointSize(18);
    label->setTextFormat(Qt::RichText);
    label->setFont(font);

    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->setColumnStretch(1,1);
    mainLayout->addWidget(label,0,0);       //title
    label->setMaximumSize(180,40);
    mainLayout->addWidget(button1,1,0);     //Saving button
    mainLayout->addWidget(ui,1,1);          //Saving textbox
    ui->setMaximumSize(140,30);
    mainLayout->addWidget(button2,2,0);     //Checking button
    mainLayout->addWidget(ui2,2,1);         //Checking textbox
    ui2->setMaximumSize(140,30);
    mainLayout->addWidget(button3,3,0);     //Transfer button
    mainLayout->addWidget(button4,4,0);     //Transaction button

    setLayout(mainLayout);

    QObject::connect(this->button1, SIGNAL(clicked()),this, SLOT(showSavings()));
    QObject::connect(this->button2, SIGNAL(clicked()),this, SLOT(showCheckings()));
}

MainWindow::~MainWindow() {}

void MainWindow::showSavings() {
  Savings* savingAcc = new Savings();
  savingAcc->show();
}

void MainWindow::showCheckings() {
  Checking* checkingAcc = new Checking();
  checkingAcc->show();
}
