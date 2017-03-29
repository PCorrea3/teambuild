#include "transfer.h"
#include <QGridLayout>
#include <QFont>

Transfer::Transfer(){
    //setFixedSize(320, 220);
    title = new QLabel("Transfer Funds");
    QFont font = title->font();
    font.setPointSize(14);
    title->setFont(font);

    accTransferF = new QLabel("Account to Transfer from");
    QFont font2 = accTransferF->font();
    font2.setPointSize(10);
    accTransferF->setFont(font2);

    transferF = new QComboBox(this);
    transferF->addItem(tr("Checking Account"));
    transferF->addItem(tr("Savings Account"));

    accTransferT = new QLabel("Account to Transfer to:");
    accTransferT->setFont(font2);

    transferT = new QComboBox(this);
    transferT->addItem(tr("Checking Account"));
	transferT->addItem(tr("Savings Account"));

    QSpinBox *priceSpinBox = new QSpinBox;
    priceSpinBox->setMinimum(0);
    priceSpinBox->setMaximum(100000000);
    priceSpinBox->setPrefix("Transfer:$");

    ok = new QPushButton("Ok");
    cancel = new QPushButton("Cancel");

    QGridLayout *layout = new QGridLayout();
    layout->setColumnStretch(1,1);
    layout->addWidget(title, 0,0);
    layout->addWidget(accTransferF,1,0);
    layout->addWidget(transferF,1,1);
    layout->addWidget(accTransferT,2,0);
    layout->addWidget(transferT,2,1);
    layout->addWidget(priceSpinBox,3,0);
    layout->addWidget(ok, 4, 0);
    layout->addWidget(cancel, 4,1);

    setLayout(layout);

	QObject::connect(
				this->cancel, SIGNAL(clicked()),
				this, SLOT(cancelButton())
			);
    QObject::connect(
				this->transferF, SIGNAL(currentIndexChanged(int)),
				this, SLOT(dropDownChange(int))
			);
	dropDownChange(0);
}
Transfer::~Transfer() {}
void Transfer::dropDownChange(int index) {
    if(index==0) {
        selected = AccountType::CHECKING;
        transferT->setCurrentIndex(1);
    } else if(index==1) {
        selected = AccountType::SAVINGS;
        transferT->setCurrentIndex(0);
    }
}

void Transfer::cancelButton() {
     this->close();
}
