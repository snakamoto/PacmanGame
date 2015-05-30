#-------------------------------------------------
#
# Project created by QtCreator 2015-05-27T23:01:02
#
#-------------------------------------------------

QT       += core gui
QT      += network
QT      += xmlpatterns
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++0x
TARGET = PacmanGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    astar.cpp \
    connection.cpp \
    highscorefile.cpp \
    Path.cpp \
    removeenemystruct.cpp \
    tiledmap.cpp \
    tile_node.cpp \
    clickablelabel.cpp \
    pacman.cpp \
    pacgraphicsscene.cpp \
    mainmenu.cpp \
    powerup.cpp \
    pellet.cpp \
    monster.cpp \
    tileset.cpp

HEADERS  += mainwindow.h \
    astar.h \
    connection.h \
    highscore.h \
    highscorefile.h \
    Path.h \
    playersyncstruct.h \
    removeenemystruct.h \
    tiledmap.h \
    tile_node.h \
    pacmanstruct.h \
    clickablelabel.h \
    pacman.h \
    pacgraphicsscene.h \
    mainmenu.h \
    powerup.h \
    powerupstruct.h \
    pellet.h \
    pelletstruct.h \
    tileset.h \
    constants.h \
    monstersstruct.h \
    monster.h \
    pathstruct.h

FORMS    += \
    mainmenu.ui

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

RESOURCES += \
    resources.qrc
