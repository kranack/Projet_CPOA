
TARGET = image
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += ../vectorMatrix

SOURCES += *.cpp \
    image2grey.cpp \
    image2rgb.cpp

HEADERS += *.h *.hpp \
    image.h \
    imgGradient.h \
    image2.h \
    image2grey.h \
    image2rgb.h

DESTDIR = ../lib


