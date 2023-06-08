#-------------------------------------------------
#
# Project created by QtCreator 2023-05-26T22:07:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHomeClient
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DateTimeInfo.cpp \
    TemperatureIn.cpp

HEADERS  += Widget.h \
    DateTimeInfo.h \
    TemperatureIn.h

FORMS    += Widget.ui \
    DateTimeInfo.ui \
    TemperatureIn.ui
