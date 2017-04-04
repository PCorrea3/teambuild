// MainWindow.cpp
#include "window.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(420, 320);

    setVisible(false);
    button1 = new QPushButton("Savings Account");
    button2 = new QPushButton("Checking Account");
    button3 = new QPushButton("Transfer Funds");
    button4 = new QPushButton("Transaction History");

    ui->setText(QString::number(checking,'F',2));
    ui->setReadOnly(true);

    ui2->setText(QString::number(savings, 'F', 2));
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
    mainLayout->addWidget(button2,1,0);      //Checking button

    mainLayout->addWidget(ui,1,1);          //Checking textbox
    ui->setMaximumSize(140,30);
    mainLayout->addWidget(button1,2,0);     //Saving button

    mainLayout->addWidget(ui2,2,1);         //Saving textbox
    ui2->setMaximumSize(140,30);
    mainLayout->addWidget(button3,3,0);     //Transfer button
    mainLayout->addWidget(button4,4,0);     //Transaction history button

    setLayout(mainLayout);

    connect(this->button1, SIGNAL(clicked()),this, SLOT(showSavings()));
    connect(this->button2, SIGNAL(clicked()),this, SLOT(showCheckings()));
    connect(this->button3, SIGNAL(clicked()),this, SLOT(showTransfer()));
    connect(this->transWindow->getTransferButton(),SIGNAL(clicked()),
           this, SLOT(transferFunds()));
    connect(this, SIGNAL(onCheckingBalanceChange(double)),
            this->checkingAcc, SLOT(updateCheckingBalance(double)));
}

MainWindow::~MainWindow() {}
double MainWindow::debtChecking(double amt) {
    this->checking+=amt;
    return checking;
}
double MainWindow::debtSavings(double amt) {
    savings+=amt;
    return savings;
}
void MainWindow::showSavings() {
  Savings* savingAcc = new Savings();
  savingAcc->show();
}

void MainWindow::showCheckings() {
  checkingAcc->show();
}

void MainWindow::showTransfer(){
    transWindow->setVisible(!transWindow->isVisible());
}
void MainWindow::transferFunds() {
    double amt = transWindow->getTextAmt();

    if(transWindow->getSelected() == Transfer::AccountType::CHECKING) {
        if((checking - amt - 35) >= -300) {
            if(checking<=0) {
            checking -=35;
            }
          savings+=amt;
          checking-=amt;
          emit onCheckingBalanceChange(checking);
       }
    } else if(transWindow->getSelected() == Transfer::AccountType::SAVINGS) {
        if(savings>=amt) {
          savings-=amt;
          checking+=amt;
          //emit onSavingsBalanceChange(savings);
        }
    }

    ui->setText(QString::number(checking,'F',2));
    ui2->setText(QString::number(savings, 'F', 2));
}
