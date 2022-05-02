#ifndef ___ROBOTTHREAD_H___
#define ___ROBOTTHREAD_H___

#include <QtCore>
#include <QThread>
#include <QStringList>
#include <stdlib.h>
#include <string>
#include <QMutex>
#include <iostream>
#include "assert.h"
#include <sstream>

#include <ros/ros.h>
#include <ros/network.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include "std_msgs/String.h"
class RobotThread : public QObject {
	Q_OBJECT
public:
    RobotThread(int argc, char **pArgv, const char * topic  = "ros_gui");
    virtual ~RobotThread();


    bool init();

    void poseCallback(const std_msgs::String::ConstPtr& msg);
    void pubPose();

    Q_SLOT void run();
    Q_SIGNAL void newPose(int,int,int,int);

private:
    int m_Init_argc;
    char** m_pInit_argv;
    const char * m_topic;



    QThread * m_pThread;

    ros::Subscriber sub_chess;
    ros::Publisher  pub_chess_group;

    std_msgs::String str_chess_position;
    std::stringstream ss;
};
#endif
