#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; roscore'&");
    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; roslaunch subscriber_mini_bot start_demo.launch'&");

}

void MainWindow::on_pushButton_3_clicked()
{
    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; rosrun opencv_zed_ros opencv_zed_ros'&");
}

void MainWindow::on_pushButton_2_clicked()
{
    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; rosrun qt_app qt_app_node'&");
}

void MainWindow::on_pushButton_4_clicked()
{
	std_msgs::String msg;
	std::stringstream ss;
	ss<<"ok";
	msg.data=ss.str();
	chatter_pub.publish(msg);
}

void MainWindow::on_pushButton_5_clicked()
{
    system("gnome-terminal -- rosnode kill chess_game");
}

void MainWindow::on_pushButton_6_clicked()
{
    system("gnome-terminal -- rosnode kill --all");	
    close();
}

void MainWindow::on_pushButton_7_clicked()
{
    //disconnect
    system("gnome-terminal -- rosnode kill planned_path_subscriber robot_state_publisher");

}

void MainWindow::on_pushButton_8_clicked()
{
    //camera
    system("gnome-terminal -- rosnode kill image_publisher");
}
