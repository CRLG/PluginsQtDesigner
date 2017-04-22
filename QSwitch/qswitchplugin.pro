CONFIG      += plugin debug_and_release
TEMPLATE    = lib
TARGET      = $$qtLibraryTarget($$TARGET)

QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

HEADERS     = qswitch.h \
              qswitchplugin.h
SOURCES     = qswitch.cpp \
              qswitchplugin.cpp

RESOURCES   = qswitch.qrc

# install
target.path = $$[QT_INSTALL_PLUGINS]/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/qswitchplugin
INSTALLS += target sources
