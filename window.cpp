// Window.cpp
#include "window.h"
#include "mainwindow.h"
#include<QDebug>

Window::Window(QWidget *parent) : QWidget(parent) {
    setFixedSize(240, 180);
    submit = new QPushButton("Submit");

    usernameLabel = new QLabel("Username:");
    passwordLabel = new QLabel("Password:");
    QFont font = usernameLabel->font();
    font.setPointSize(14);
    usernameLabel->setFont(font);
    passwordLabel->setFont(font);

    username = new QLineEdit(this);
    username->setMaximumSize(120,30);

    password = new QLineEdit(this);
    password->setMaximumSize(120,30);
    password->setEchoMode(QLineEdit::Password);

    //formatting
    QGridLayout *layout = new QGridLayout();
    layout->setColumnStretch(1,1);
    layout->addWidget(usernameLabel,0,0);
    layout->addWidget(username,0,1);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(password, 1,1);
    layout->addWidget(submit, 2,1);

    setLayout(layout);

    QObject::connect(this->submit, SIGNAL(clicked()),this, SLOT(showWindow()));

}
Window::~Window() {}

void Window::showWindow() {
     str = username->text();
     str2 = password->text();
    if(str == "john" && str2 == "password")
    {

    MainWindow* mainW = new MainWindow();
    mainW->show();
    this->close();
    }

}

