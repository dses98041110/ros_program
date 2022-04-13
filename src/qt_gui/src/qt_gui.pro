QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt

INCLUDEPATH+=/opt/ros/melodic/include

LIBS+= -L/opt/ros/melodic/lib

SOURCES += main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h
