# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Bridge
DESTDIR = ../x64/Debug
QT += core gui widgets
CONFIG += debug console
DEFINES += _UNICODE _ENABLE_EXTENDED_ALIGNED_STORAGE WIN64 QT_DLL QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
win32:RC_FILE = Bridge.rc
HEADERS += ./NDItem.h \
    ./WYItem.h \
    ./Bridge.h \
    ./AttributeForm.h \
    ./Item.h \
    ./Scene.h \
    ./YBItem.h
SOURCES += ./AttributeForm.cpp \
    ./Bridge.cpp \
    ./Item.cpp \
    ./main.cpp \
    ./NDItem.cpp \
    ./Scene.cpp \
    ./WYItem.cpp \
    ./YBItem.cpp
FORMS += ./Attribute.ui \
    ./Bridge.ui
RESOURCES += Bridge.qrc
