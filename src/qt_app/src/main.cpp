#include "mainwindow.h"
#include <QApplication>
#include <Game.h>
#include <ros/ros.h>
#include "std_msgs/String.h"
#include <thread>

Game *game;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
int main(int argc, char *argv[])
{

    // initialize
    ros::init(argc, argv, "chess_game");
    ros::NodeHandle nh;
    ros::Rate rate = ros::Rate(0.25);
    ros::Subscriber sub_chess = nh.subscribe("chess_position", 5, chatterCallback); 

    QApplication a(argc, argv);
    game =new Game();
    game->show();
    game->initializeChessPieceMoveBoards();

    game->drawChessBoard();

    game->addChessPiece();
    //ros::spin();
    return a.exec();
}
