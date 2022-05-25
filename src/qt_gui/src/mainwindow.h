#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QProcess>
#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("zed_take_picture", 1000);
};

#endif // MAINWINDOW_H
