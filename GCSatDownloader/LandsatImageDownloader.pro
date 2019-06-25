#-------------------------------------------------
#
# Project created by QtCreator 2015-06-11T15:43:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LandsatImageDownloader
TEMPLATE = app


SOURCES += main.cpp\
        landsatimagedownloader.cpp \
    calendarwidget.cpp

HEADERS  += landsatimagedownloader.h \
    calendarwidget.h

FORMS    += landsatimagedownloader.ui \
    calendarwidget.ui

DISTFILES +=

RESOURCES += \
    logos.qrc
