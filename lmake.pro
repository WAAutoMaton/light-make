QT += core
QT -= gui

CONFIG += c++11

TARGET = lmake
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

TRANSLATIONS += lmake_zh_CN.ts

SOURCES += main.cpp \
    core.cpp \
    configreader.cpp \
    data.cpp \
    makefilewritter.cpp \
    stringtools.cpp \
    error.cpp


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += \
    rc.qrc

HEADERS += \
    core.h \
    configreader.h \
    data.h \
    makefilewritter.h \
    stringtools.h \
    error.h
