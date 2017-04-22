CONFIG      += plugin debug_and_release
TEMPLATE    = lib
TARGET      = $$qtLibraryTarget($$TARGET)

# CONFIG                 += debug_and_release

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

#DEFINES                += QT_NO_CAST_FROM_ASCII \
#                          QT_NO_CAST_TO_ASCII \
#                          QT_NO_KEYWORD

HEADERS                += qledmatrix.h \
                          qledmatrixplugin.h

SOURCES                += qledmatrix.cpp \
                          qledmatrixplugin.cpp

RESOURCES              += qledmatrix.qrc

