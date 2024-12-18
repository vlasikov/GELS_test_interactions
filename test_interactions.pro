#-------------------------------------------------
#
# Project created by QtCreator 2012-03-04T23:24:55
#
#-------------------------------------------------

QT       += network core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += c++11
lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -std=c++11

TARGET = interaction-example
TEMPLATE = app

SOURCES += main.cpp\
        client.cpp \
        mainwindow.cpp \
        point_tag.cpp \
        qcustomplot.cpp

HEADERS  += mainwindow.h \
         client.h \
         point_tag.h \
         qcustomplot.h

FORMS    += mainwindow.ui

