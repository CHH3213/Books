#-------------------------------------------------
#
# Project created by QtCreator 2018-01-05T14:35:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02_SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    teacher.cpp \
    student.cpp

HEADERS  += widget.h \
    teacher.h \
    student.h

FORMS    += widget.ui

CONFIG += c++11
