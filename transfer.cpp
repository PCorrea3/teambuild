#include "transfer.h"
#include <QGridLayout>
#include <QFont>

Transfer::Transfer(){
    title = new QLabel("Transfer Funds");
    QFont font = title->font();
    font.setPointSize(14);

    ok = new QPushButton("Ok");
    cancel = new QPushButton("Cancel");

    QGridLayout *layout = new QGridLayout();
    layout->setColumnStretch(1,1);
    layout->addWidget(title, 0,0);
    layout->addWidget(ok, 1, 0);
    layout->addWidget(cancel, 1,1);

    setLayout(layout);
}
Transfer::~Transfer() {}
