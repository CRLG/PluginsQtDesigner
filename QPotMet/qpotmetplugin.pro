CONFIG += plugin debug_and_release
TEMPLATE = lib
TARGET = $$qtLibraryTarget($$TARGET)

QTDIR_build:DESTDIR = $$QT_BUILD_TREE/plugins/designer

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

HEADERS = qpotmet.h qpotmetplugin.h
SOURCES = qpotmet.cpp qpotmetplugin.cpp

RESOURCES += qpotmet.qrc
