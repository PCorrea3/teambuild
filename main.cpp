//main.cpp
#include <QtGui>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QLabel>
#include "window.h"
#include "savings.h"
#include "mainwindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

//    Window window;
//    window.show();
    MainWindow mainW;
    mainW.show();

    return app.exec();
}
