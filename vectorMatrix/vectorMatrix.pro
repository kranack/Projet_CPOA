
TARGET = vectorMatrix
TEMPLATE = lib
CONFIG += staticlib

#INCLUDEPATH +=

#SOURCES += *.cpp
SOURCES += vectCalc.cpp \
    matrix33f.cpp \
    vec2f.cpp \
    vec3f.cpp

#HEADERS += *.h *.hpp
HEADERS += vecttempl.h vectCalc.h \
    array.h \
    matrix33f.h \
    vec2f.h \
    vec3f.h \
    vector.h \
    image.h

DESTDIR = ../lib

QMAKE_CXXFLAGS += -Wall

