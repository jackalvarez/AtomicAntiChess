#ifndef GAME_H
#define GAME_H

#include <QApplication>

class QGraphicsScene;
class QSvgRenderer;
class QGraphicsView;
class Player;
class Score;
class Board;

/**
	Game controller. An object that represents the game.
*/
class Game : public QApplication
{
	Q_DISABLE_COPY(Game)

  protected:
	// Manages graphic items. It is an invisible manager
	QGraphicsScene* scene;
	/// A visible widget that renders the scene
    QGraphicsView* view;
	/// Shows the score on the screen to the player
	Score* score;
	/// Parsers the assets svg file
	QSvgRenderer* svgRenderer = nullptr;
    /// Keeps pointers to the pieces
    Board* board;

  public:
	/// Constructor
	Game(int &argc, char **argv, int flags = ApplicationFlags);
	/// Destructor
	~Game();
	/// Call this method instead of exec()
	int run();
	/// Play the given filename as background music
	void playBackgroundMusic(const QString& audioFilename);

  protected slots:
};

#endif // GAME_H
