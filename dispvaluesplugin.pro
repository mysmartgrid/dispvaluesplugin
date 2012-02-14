TARGET = dispvaluesplugin
TEMPLATE = lib
CONFIG += dll

QT += network

DESTDIR = ../

SOURCES += src/main.cpp \
 src/dispval.cpp \
 src/json/json.cpp \
 src/plotter/plotsettings.cpp \
 src/plotter/plotter.cpp \
 src/plotter/qpointd.cpp
HEADERS += src/dispval.h \
 src/json/json.h \
 src/plotter/plotsettings.h \
 src/plotter/plotter.h \
 src/plotter/converter.h \
 src/plotter/qpointd.h

RESOURCES += \
    dispval.qrc
