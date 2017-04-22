CONFIG += plugin debug_and_release
TEMPLATE = lib
TARGET = $$qtLibraryTarget($$TARGET)

QTDIR_build:DESTDIR = $$QT_BUILD_TREE/plugins/designer

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

HEADERS = qprog.h qprogplugin.h
SOURCES = qprog.cpp qprogplugin.cpp

RESOURCES += qprog.qrc
