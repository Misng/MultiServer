#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T09:32:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MultiServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    timeserver.cpp \
    childthread.cpp

HEADERS  += mainwidget.h \
    timeserver.h \
    childthread.h

FORMS    += mainwidget.ui
