#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    
    ui->setupUi(this);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_4->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; roscore'&");
    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; roslaunch subscriber_mini_bot start_demo.launch;'&");
    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; rosrun minibot_control test_mover'&");
    ui->pushButton->setEnabled(false);
    ui->pushButton_7->setEnabled(true);

}

void MainWindow::on_pushButton_3_clicked()
{
    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; rosrun opencv_zed_ros opencv_zed_ros'&");
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_4->setEnabled(true);

}

void MainWindow::on_pushButton_2_clicked()
{
    system("gnome-terminal -- bash -c 'source ~/catkin_ws/devel/setup.bash; rosrun qt_app qt_app_node'&");
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_5->setEnabled(true);
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
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    system("gnome-terminal -- rosnode kill --all");	
    close();
}

void MainWindow::on_pushButton_7_clicked()
{
    //disconnect
    system("gnome-terminal -- rosnode kill planned_path_subscriber robot_state_publisher test_mover");
    ui->pushButton_7->setEnabled(false);
    ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_8_clicked()
{
    //camera
    system("gnome-terminal -- rosnode kill image_publisher");
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
}
