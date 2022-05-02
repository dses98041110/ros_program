#include <iostream>
#include <QApplication>
#include "mainwindow.h"
using namespace std;

int main(int argc,char *argv[])
{
    cout << "Hello World!" << endl;
    ros::init(argc, argv, "ros_gui");
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
