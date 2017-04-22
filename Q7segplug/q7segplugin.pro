CONFIG += plugin debug_and_release
TEMPLATE = lib
TARGET = $$qtLibraryTarget($$TARGET)

QTDIR_build:DESTDIR = $$QT_BUILD_TREE/plugins/designer

HEADERS = q7seg.h q7segplugin.h
SOURCES = q7seg.cpp q7segplugin.cpp

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

RESOURCES += q7seg.qrc
