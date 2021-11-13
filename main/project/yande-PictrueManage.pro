#-------------------------------------------------
#
# Project created by QtCreator 2021-10-24T18:19:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yande-PictrueManage
TEMPLATE = app
DESTDIR = $$PWD/../bin

INCLUDEPATH += $$PWD/src/cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

msvc{
        QMAKE_CFLAGS += -source-charset:utf-8  -execution-charset:utf-8
        QMAKE_CXXFLAGS += -source-charset:utf-8 -execution-charset:utf-8
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        src/cpp/filereader/filereader.cpp \
        src/cpp/qssmanager/qssmanager.cpp \
        src/main.cpp \
        src/ui/mainwindow.cpp \
        src/ui/parts/items/showitemform.cpp \
        src/ui/parts/items/tagsitemform.cpp \
        src/ui/parts/leftsearchform.cpp \
        src/ui/parts/rightshowform.cpp

HEADERS += \
        src/cpp/filereader/filereader.h \
        src/cpp/qssmanager/qssmanager.h \
        src/ui/mainwindow.h \
        src/ui/parts/items/showitemform.h \
        src/ui/parts/items/tagsitemform.h \
        src/ui/parts/leftsearchform.h \
        src/ui/parts/rightshowform.h

FORMS += \
        src/ui/mainwindow.ui \
        src/ui/parts/items/showitemform.ui \
        src/ui/parts/items/tagsitemform.ui \
        src/ui/parts/leftsearchform.ui \
        src/ui/parts/rightshowform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse/resourse.qrc
