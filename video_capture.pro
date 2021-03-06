#-------------------------------------------------
#
# Project created by QtCreator 2021-08-12T21:25:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = video_capture
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

SOURCES += \
        camera_node.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        camera_node.hpp \
        mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += \
                /usr/include/opencv \
                /usr/include/opencv2 \
                /usr/local/include/imgcodecs \
                /home/cto/workspace/darknet/include \
                /home/cto/workspace/darknet/src

LIBS += -L/usr/local/lib \
        -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgcodecs \
        -lopencv_videoio \
        -lopencv_imgproc
#        -ldarknet

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
