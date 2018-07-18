#-------------------------------------------------
#
# Project created by QtCreator 2018-07-15T12:29:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += core gui widgets svg multimedia

TARGET = AtomicAntiChess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES

HEADERS

HEADERS += \
    Score.h \
    Game.h \
    Score.h \
    Piece.h \
    Board.h \
    Pawn.h \
    Rook.h \
    Queen.h \
    Knight.h \
    King.h \
    Bishop.h

SOURCES += \
    main.cpp \
    Score.cpp \
    Game.cpp \
    Piece.cpp \
    Pawn.cpp \
    Board.cpp \
    Rook.cpp \
    Queen.cpp \
    Knight.cpp \
    King.cpp \
    Bishop.cpp

RESOURCES += \
    ../Assets/assets.qrc
