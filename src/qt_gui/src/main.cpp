#include <iostream>
#include <QApplication>
#include "mainwindow.h"
using namespace std;

int main(int argc,char *argv[])
{
    system("gnome-terminal -- bash -c 'roscroe'&");
    ros::init(argc, argv, "ros_gui");
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
