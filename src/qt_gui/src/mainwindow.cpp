#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    m_RobotThread(0, 0,"ros_gui")
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

}
