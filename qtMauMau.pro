#-------------------------------------------------
#
# Project created by QtCreator 2014-04-10T09:38:37
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = qtMauMau
TEMPLATE = app
CONFIG += c++11
CONFIG += testcase



SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    network/server.cpp \
    network/client.cpp \
    gameLogic/deck.cpp \
    gameLogic/card.cpp \
    gui/playground.cpp \
    gui/optiondialog.cpp \
    gui/carditem.cpp \
    gui/playeritem.cpp \
    gameLogic/Test/gamecontroller_test.cpp \
    gameLogic/Test/decktest.cpp \
    gui/animatedgraphicsscene.cpp \
    gameLogic/gamecontroller.cpp \
    gameLogic/humanplayer.cpp \
    gameLogic/aiplayer.cpp \
    gameLogic/remoteplayer.cpp \
    gameLogic/player.cpp \
    gui/choosecolordialog.cpp \
    gameLogic/gamecontrollerproxy.cpp \
    gameLogic/gamestate.cpp
    gui/choosecolordialog.cpp



HEADERS  += mainwindow.h \
    settings.h \
    network/server.h \
    network/client.h \
    gameLogic/gamecontroller.h \
    gameLogic/card.h \
    gameLogic/deck.h \
    gui/playground.h \
    gui/optiondialog.h \
    gui/carditem.h \
    gui/playeritem.h \
    gameLogic/Deck.h \
    gameLogic/Test/gamecontroller_test.h \
    gameLogic/Test/decktest.h \
    gui/animatedgraphicsscene.h \
    gameLogic/player.h \
    gameLogic/humanplayer.h \
    gameLogic/aiplayer.h \
    gameLogic/remoteplayer.h \
    gui/choosecolordialog.h \
    gameLogic/gamecontrollerproxy.h \
    gameLogic/gamestate.h \
    gameLogic/PlayerName.h
    gui/choosecolordialog.h


FORMS    += \
    gui/optiondialog.ui \
    gui/choosecolordialog.ui


TRANSLATIONS    = qtmaumau_de.ts \


# Decide if its Debug or Release
CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug

# Copy images,config etc. in the build folder
images.path    = $$DESTDIR/img
images.files   = img/*
config.path    = $$DESTDIR/
config.files   = config.ini
translation.path    = $$DESTDIR/
translation.files   = qtmaumau_de.qm
INSTALLS       += images config translation

