#-------------------------------------------------
#
# Project created by QtCreator 2013-09-19T18:33:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhotoID
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp

HEADERS  += mainwindow.h \
    image.h \
    photoType.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resource.qrc
