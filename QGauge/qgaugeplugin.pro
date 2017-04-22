CONFIG      += plugin debug_and_release
TEMPLATE    = lib
TARGET      = $$qtLibraryTarget($$TARGET)

QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

HEADERS     = qgauge.h \
              qgaugeplugin.h
SOURCES     = qgauge.cpp \
              qgaugeplugin.cpp

RESOURCES = qgauge.qrc

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

