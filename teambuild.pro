TEMPLATE = app
TARGET = my_app

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
HEADERS += \
    window.h \
    mainwindow.h \
    savings.h \
    checking.h

SOURCES += \
    window.cpp \
    main.cpp \
    mainwindow.cpp \
    savings.cpp \
    checking.cpp
