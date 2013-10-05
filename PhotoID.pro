#-------------------------------------------------
#
# Project created by QtCreator 2013-09-19T18:33:45
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhotoID
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    image.cpp \
    paper.cpp

HEADERS  += mainwindow.h \
    image.h \
    photoType.h \
    paper.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resource.qrc
