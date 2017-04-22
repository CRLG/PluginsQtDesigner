#-------------------------------------------------
#
# Project created by QtCreator 2014-07-21T12:19:41
#
#-------------------------------------------------
QT       += core gui testlib xml printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qHexEdit
TEMPLATE = app

SOURCES +=  main.cpp\
            test.cpp\
            ../QHexEdit/qhexedit.cpp\
            ../QHexEdit/qhexeditcomments.cpp \
            ../QHexEdit/qhexeditdata.cpp \
            ../QHexEdit/qhexeditdatadevice.cpp \
            ../QHexEdit/qhexeditdatareader.cpp \
            ../QHexEdit/qhexeditdatawriter.cpp \
            ../QHexEdit/qhexedithighlighter.cpp \
            ../QHexEdit/qhexeditprivate.cpp \
            ../QHexEdit/sparserangemap.cpp
 


INCLUDEPATH +=  ./ \
                ../QHexEdit \
			
			
HEADERS  += test.h \
    ../QHexEdit/qhexedit.h \
    ../QHexEdit/qhexeditcomments.h \
    ../QHexEdit/qhexeditdata.h \
    ../QHexEdit/qhexeditdatadevice.h \
    ../QHexEdit/qhexeditdatareader.h \
    ../QHexEdit/qhexeditdatawriter.h \
    ../QHexEdit/qhexedithighlighter.h \
    ../QHexEdit/qhexeditprivate.h \
    ../QHexEdit/sparserangemap.h

RESOURCES+= test.qrc \

FORMS += \
    test.ui




