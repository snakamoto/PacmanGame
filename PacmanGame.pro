#-------------------------------------------------
#
# Project created by QtCreator 2015-05-27T23:01:02
#
#-------------------------------------------------

QT       += core gui
QT      += network
QT      += xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    enemy.cpp \
    tdgraphicsscene.cpp \
    pacman.cpp

HEADERS  += mainwindow.h \
    astar.h \
    connection.h \
    enemystruct.h \
    highscore.h \
    highscorefile.h \
    Path.h \
    playersyncstruct.h \
    removeenemystruct.h \
    tiledmap.h \
    tile_node.h \
    pacmanstruct.h \
    clickablelabel.h \
    Constants.h \
    enemy.h \
    tdgraphicsscene.h \
    pacman.h

FORMS    += mainwindow.ui
