#-------------------------------------------------
#
# Project created by QtCreator 2017-06-16T12:06:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tuner
TEMPLATE = app


SOURCES += main.cpp\
        tuner.cpp \
    aboutdialog.cpp \
    newinstrumentdialog.cpp \
    addstringdialog.cpp \
    instrumentmodel.cpp \
    editinstrumentsdialog.cpp

HEADERS  += tuner.h \
    aboutdialog.h \
    newinstrumentdialog.h \
    addstringdialog.h \
    instrumentmodel.h \
    editinstrumentsdialog.h

FORMS    += tuner.ui \
    aboutdialog.ui \
    newinstrumentdialog.ui \
    addstringdialog.ui \
    editinstrumentsdialog.ui

DISTFILES +=
