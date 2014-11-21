
TARGET = image
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../vectorMatrix

SOURCES += *.cpp

HEADERS += *.h *.hpp \
    image.h

DESTDIR = ../lib

