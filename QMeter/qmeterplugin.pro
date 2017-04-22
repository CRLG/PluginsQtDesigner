CONFIG      += plugin debug_and_release
TEMPLATE    = lib
TARGET      = $$qtLibraryTarget($$TARGET)

QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

# VERSION = 0.5.1

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

HEADERS     += qmeter.h \
              qmeterplugin.h \
              qmetertaskmenu.h \
              properties_dialog.h             
SOURCES     += qmeter.cpp \
              qmeterplugin.cpp \
              qmetertaskmenu.cpp \
              properties_dialog.cpp \           
              qmeterdrawfunctions.cpp

FORMS        += properties.ui

RESOURCES    = qmeter.qrc
