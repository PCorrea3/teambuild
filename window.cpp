// Window.cpp
#include "window.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QFont>

Window::Window(QWidget *parent) : QWidget(parent) {
    setFixedSize(240, 180);
    submit = new QPushButton("Submit");

    QLabel *label = new QLabel("Username:");
    QLabel *label2 = new QLabel("Password:");
    QFont font = label->font();
    font.setPointSize(14);
    label->setFont(font);
    label2->setFont(font);

    ui = new QLineEdit(this);
    ui->setMaximumSize(120,30);
    ui2 = new QLineEdit(this);
    ui2->setMaximumSize(120,30);
    ui2->setEchoMode(QLineEdit::Password);

    //formatting
    QGridLayout *layout = new QGridLayout();
    layout->setColumnStretch(1,1);
    layout->addWidget(label,0,0);
    layout->addWidget(ui,0,1);
    layout->addWidget(label2, 1, 0);
    layout->addWidget(ui2, 1,1);
    layout->addWidget(submit, 2,1);

    setLayout(layout);

    QObject::connect(this->submit, SIGNAL(clicked()),this, SLOT(showWindow()));
}
Window::~Window() {}

void Window::showWindow() {
    MainWindow* mainW = new MainWindow();
    mainW->show();
    this->close();
}
