//main.cpp
#include <QApplication>
#include "window.h"
#include "mainwindow.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	//Window window;
	//window.show();
	MainWindow mainW;
	mainW.show();
	return app.exec();
}
