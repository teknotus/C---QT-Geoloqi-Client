# -------------------------------------------------
# Project created by QtCreator 2011-11-19T14:06:29
# -------------------------------------------------
QT += core gui network
TARGET = geoloqi
TEMPLATE = app
SOURCES += main.cpp \
   loqiwindow.cpp \
   qgeoloqi.cpp \
   qgeoloqireply.cpp \
    authdialog.cpp \
    apitestbuttons.cpp \
    locationhistoryrequest.cpp \
    coordinates.cpp \
    netmanager.cpp \
    nettracker.cpp \
    mainwindow.cpp \
    locationhistorysearchwidget.cpp \
    lochissearchresultswidget.cpp \
    lochiswidget.cpp
HEADERS += loqiwindow.h \
   qgeoloqi.h \
   qgeoloqireply.h \
    authdialog.h \
    apitestbuttons.h \
    locationhistoryrequest.h \
    coordinates.h \
    netmanager.h \
    nettracker.h \
    mainwindow.h \
    locationhistorysearchwidget.h \
    lochissearchresultswidget.h \
    lochiswidget.h
LIBS += -lqjson
