// MainWindow.cpp
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(420, 320);

    setVisible(false);
    savingsButton = new QPushButton("Savings Account");
    checkingButton = new QPushButton("Checking Account");
    transferButton = new QPushButton("Transfer Funds");
    historyButton = new QPushButton("Transaction History");

    checkingAmt->setText(QString::number(checking,'F',2));
    checkingAmt->setReadOnly(true);

    savingsAmt->setText(QString::number(savings, 'F', 2));
    savingsAmt->setReadOnly(true);

    QLabel* label=new QLabel("Bank Application");
    QFont font = label->font();
    font.setPointSize(18);
    label->setTextFormat(Qt::RichText);
    label->setFont(font);

    QGridLayout* mainLayout = new QGridLayout();
    mainLayout->setColumnStretch(1,1);
    mainLayout->addWidget(label,0,0);       //title
    label->setMaximumSize(180,40);
    mainLayout->addWidget(checkingButton,1,0);    //Checking button

    mainLayout->addWidget(checkingAmt,1,1);          //Checking textbox
    checkingAmt->setMaximumSize(140,30);
    mainLayout->addWidget(savingsButton,2,0);     //Saving button

    mainLayout->addWidget(savingsAmt,2,1);         //Saving textbox
    savingsAmt->setMaximumSize(140,30);
    mainLayout->addWidget(transferButton,3,0);     //Transfer button
    mainLayout->addWidget(historyButton,4,0);     //Transaction history button

    setLayout(mainLayout);
	checkingAcc->updateCheckingBalance(checking);
	savingsAcc->updateSavingsBalance(savings);

    connect(this->savingsButton, SIGNAL(clicked()),this, SLOT(showSavings()));
    connect(this->checkingButton, SIGNAL(clicked()),this, SLOT(showCheckings()));
    connect(this->transferButton, SIGNAL(clicked()),this, SLOT(showTransfer()));
    connect(this->transWindow->getTransferButton(),SIGNAL(clicked()),
           this, SLOT(transferFunds()));
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
  savingsAcc->show();
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
       }
    } else if(transWindow->getSelected() == Transfer::AccountType::SAVINGS) {
        if(savings>=amt) {
          savings-=amt;
          checking+=amt;
        }
    }
    checkingAmt->setText(QString::number(checking,'F',2));
    savingsAmt->setText(QString::number(savings, 'F', 2));
	checkingAcc->updateCheckingBalance(checking);
	savingsAcc->updateSavingsBalance(savings);
}

