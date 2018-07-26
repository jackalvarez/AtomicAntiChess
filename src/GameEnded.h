#ifndef GAMEENDED_H
#define GAMEENDED_H

#include <QDialog>

namespace Ui {
class GameEnded;
}

class GameEnded : public QDialog
{
    Q_OBJECT

public:
    /// Constructor. It setups the UI and the text of the label.
    explicit GameEnded(const QString& winner, QWidget *parent = 0);
    ~GameEnded();

    /// It gets if the button to end the game was pressed.
    inline bool getEndGame() { return endGame; }
    /// It gets if the button to reset the game was pressed.
    inline bool getResetGame() { return resetGame; }

private slots:
    /// If the exit button is clicked, it sets endGame as true and closes the window.
    void on_exitButton_clicked();
    /// If the reset button is clicked, it sets resetGame as true and closes the window.
    void on_resetButton_clicked();

private:
    Ui::GameEnded *ui;
    /// Used to know if the players want to end the game.
    bool endGame;
    /// Used to know if the players want to reset the game.
    bool resetGame;
};

#endif // GAMEENDED_H
