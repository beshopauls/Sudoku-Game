#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T22:10:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sudoku-qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matrix.cpp \
    rdarray.cpp

HEADERS  += mainwindow.h \
    matrix.h \
    rdarray.h

FORMS    += mainwindow.ui

RESOURCES +=
