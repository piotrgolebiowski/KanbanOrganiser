QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
QT += core network widgets xml

TEMPLATE = app

SRC_PATH = ../../Organiser
INCLUDEPATH += $$SRC_PATH
DEPENDPATH += $$SRC_PATH

SOURCES +=  tst_noteswriterxml.cpp \
     $$SRC_PATH/datastructures/card/card.cpp \
     $$SRC_PATH/datastructures/notes/notes.cpp \
     $$SRC_PATH/datastructures/card/cardwriterxml.cpp \
     $$SRC_PATH/datastructures/notes/noteswriterxml.cpp

HEADERS += \
    test_noteswriterxml.h
