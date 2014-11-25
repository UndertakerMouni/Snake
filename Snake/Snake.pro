#-------------------------------------------------
#
# Project created by QtCreator 2014-11-23T21:28:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
        snake.cpp

HEADERS  += snake.h

FORMS    += snake.ui

OTHER_FILES += \
    images/apple.png \
    images/body.png \
    images/border.png \
    images/grass.png \
    images/headdown.png \
    images/headleft.png \
    images/headright.png \
    images/headup.png \
    myIcon.rc \
    images/snake.ico

RESOURCES += \
    Resource.qrc
RC_FILE +=
    myIcon.rc
