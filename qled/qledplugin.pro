CONFIG      += plugin debug_and_release
TEMPLATE    = lib
TARGET      = $$qtLibraryTarget($$TARGET)

QT += svg

QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

HEADERS     = qled.h \
              qledplugin.h
SOURCES     = qled.cpp \
              qledplugin.cpp

RESOURCES = qled.qrc

