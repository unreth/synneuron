#-------------------------------------------------
#
# Project created by QtCreator 2011-05-26T19:42:25
#
#-------------------------------------------------

QT       += core gui

TARGET = synneuron
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    neuron.h \
    layer.h \
    net.h \
    input.h

FORMS    +=

LIBS+=-L/usr/lib/kde -lkdeui
