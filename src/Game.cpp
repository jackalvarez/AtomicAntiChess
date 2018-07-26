#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSoundEffect>
#include <QTime>
#include <QTimer>

#include "Game.h"
#include "Score.h"
#include "Board.h"
Game::Game(int &argc, char **argv, int flags)
	: QApplication(argc, argv, flags)
{
}

Game::~Game()
{
	delete this->scene;
	delete this->view;
}

// ToDo: Adapt for our game.
int Game::run()
{
	// An invisible object that manages all the items
	this->scene = new QGraphicsScene();

	// A visible rectangle of the scene
	this->view = new QGraphicsView(this->scene);
  #if ! defined(Q_OS_ANDROID) && ! defined(Q_OS_IOS)
    this->view->resize(720, 695);
  #endif
    this->view->setFixedSize(850, 695);

	// Set a black color background or add an image as a background
    this->view->setBackgroundBrush(QBrush(Qt::white, Qt::Dense5Pattern));
    this->board = new Board(QPixmap(":/board.png"));

    board->setScene(this->scene);
    scene->addItem( board );
    board->addPiecesToScene();

	// The scene has infinite size, but we want it has the same size than the view
	// This stops the weird behavior of the autoscroll feature of the view being smaller than the
	// scene, because the scene auto-increases when objects are moved
	this->scene->setSceneRect( this->view->rect() );

	// Disable scrollbars because they are not longer needed
	this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// Show the view and enter in application's event loop
	this->view->show();
	return exec();
}

void Game::playBackgroundMusic(const QString& audioFilename)
{
	// We add the sound to a playlist
	QMediaPlaylist* playlist = new QMediaPlaylist();
	playlist->addMedia(QUrl("qrc:/" + audioFilename));

	// We add the playlist to a media player object
	QMediaPlayer* mediaPlayer = new QMediaPlayer(this);
	mediaPlayer->setPlaylist(playlist);

	// Play the playlist in an infinite loop
	playlist->setCurrentIndex(1);
	playlist->setPlaybackMode(QMediaPlaylist::Loop);

	// Set 2/3 of the volume and start playing the background music
	mediaPlayer->setVolume(67);
	mediaPlayer->play();
}

