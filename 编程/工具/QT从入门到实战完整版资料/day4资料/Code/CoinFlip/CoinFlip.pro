#-------------------------------------------------
#
# Project created by QtCreator 2018-01-09T09:22:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoinFlip
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    mypushbutton.cpp \
    chooselevelscene.cpp \
    playscene.cpp

HEADERS  += mainscene.h \
    mypushbutton.h \
    chooselevelscene.h \
    playscene.h

FORMS    += mainscene.ui

RESOURCES += \
    res.qrc
