#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T14:57:38
#
#-------------------------------------------------

QT       += core gui network bluetooth sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControleAcessoRU
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    login.cpp \
    optionsHandler.cpp \
    bluetooth.cpp \
    serversocket.cpp \
    recharge.cpp \
    historictransaction.cpp

HEADERS  += \
    login.h \
    optionsHandler.h \
    bluetooth.h \
    serversocket.h \
    recharge.h \
    historictransaction.h

FORMS    += \
    login.ui \
    optionsHandler.ui \
    recharge.ui \
    historictransaction.ui

CONFIG += mobility
MOBILITY = 

OTHER_FILES += \ android/AndroidManifest.xml android/res/drawable-hdpi/icon.png android/res/drawable-ldpi/icon.png android/res/drawable-mdpi/icon.png android/res/values/libs.xml android/res/values/strings.xml android/src/eu/licentia/necessitas/industrius/QtActivity.java android/src/eu/licentia/necessitas/industrius/QtApplication.java android/src/eu/licentia/necessitas/industrius/QtLayout.java android/src/eu/licentia/necessitas/industrius/QtSurface.java android/src/eu/licentia/necessitas/ministro/IMinistro.aidl android/src/eu/licentia/necessitas/ministro/IMinistroCallback.aidl android/src/eu/licentia/necessitas/mobile/QtAndroidContacts.java android/src/eu/licentia/necessitas/mobile/QtCamera.java android/src/eu/licentia/necessitas/mobile/QtFeedback.java android/src/eu/licentia/necessitas/mobile/QtLocation.java android/src/eu/licentia/necessitas/mobile/QtMediaPlayer.java android/src/eu/licentia/necessitas/mobile/QtSensors.java android/src/eu/licentia/necessitas/mobile/QtSystemInfo.java

DISTFILES += \
    images/ufsc-logo.png \
    images/ufsc-logo2.png

QMAKE_CXXFLAGS += -std=gnu++11

RESOURCES += \
    images.qrc

