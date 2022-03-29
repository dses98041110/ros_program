#include "mainwindow.h"
#include <QApplication>
#include <Game.h>
#include <ros/ros.h>
#include "std_msgs/String.h"
#include <thread>

Game *game;


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    game =new Game();
    game->show();
    game->initializeChessPieceMoveBoards();

    game->drawChessBoard();

    game->addChessPiece();

    return a.exec();
}
