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
    explicit GameEnded(const QString& winner, QWidget *parent = 0);
    ~GameEnded();


    inline bool getEndGame() { return endGame; }
    inline bool getResetGame() { return resetGame; }

protected slots:
    void endCurrentGame();
    void resetCurrentGame();
private slots:
    void on_exitButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::GameEnded *ui;
    bool endGame;
    bool resetGame;
};

#endif // GAMEENDED_H
