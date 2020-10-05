#-------------------------------------------------
#
# Project created by QtCreator 2020-09-19T09:16:14
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BWshift
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG +=resources_big

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mypushbutton.cpp \
    playscene.cpp \
    jiaocheng.cpp

HEADERS += \
        mainwindow.h \
    mypushbutton.h \
    playscene.h \
    jiaocheng.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Cloudmusic/Acreix - Visions.ncm \
    ../../Cloudmusic/Ken Arai - I AM -Piano Version-.mp3 \
    ../../qt/architecture/record.txt \
    ../../qt/architecture/record2.txt \
    ../../qt/architecture/record3.txt \
    ../../qt/architecture/record4.txt \
    ../../qt/architecture/record5.txt \
    ../../qt/architecture/record6.txt \
    ../../qt/architecture/record7.txt \
    ../../qt/architecture/record8.txt \
    ../../qt/architecture/record9.txt

RESOURCES += \
    backg.qrc \
    ic.qrc



