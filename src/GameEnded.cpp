#include "GameEnded.h"
#include "ui_GameEnded.h"

#include <iostream>

GameEnded::GameEnded(const QString& winner, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameEnded)
    , endGame { false }
    , resetGame { false }
{
    ui->setupUi(this);
    ui->winnerText->setText(winner + " player won!");
    connect(ui->exitButton, &QPushButton::clicked, this, &GameEnded::endCurrentGame);
    connect(ui->resetButton, &QPushButton::clicked, this, &GameEnded::resetCurrentGame);
}

GameEnded::~GameEnded()
{
    delete ui;
}

void GameEnded::endCurrentGame()
{
    std::cerr << "Exit\n";
    this->endGame = true;
}
void GameEnded::resetCurrentGame()
{
    std::cerr << "Reset\n";
    this->resetGame = true;
}

void GameEnded::on_exitButton_clicked()
{
    std::cerr << "Exit\n";
    this->endGame = true;
    close();
}

void GameEnded::on_resetButton_clicked()
{
    std::cerr << "Reset\n";
    this->resetGame = true;
    close();
}
