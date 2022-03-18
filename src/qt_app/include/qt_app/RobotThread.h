#ifndef ___ROBOTTHREAD_H___
#define ___ROBOTTHREAD_H___

#include <QtCore>
#include <QThread>
#include <QStringList>
#include <stdlib.h>
#include <QMutex>
#include <iostream>
#include "assert.h"

#include <ros/ros.h>



#include "std_msgs/String.h"
class RobotThread : public QObject {
	Q_OBJECT
public:
    RobotThread(int argc, char **pArgv, const char * topic  = "chess_position");
    virtual ~RobotThread();


    bool init();

    void chatterCallback(const std_msgs::String::ConstPtr& msg);


    Q_SLOT void run();


private:
    int m_Init_argc;
    char** m_pInit_argv;
    const char * m_topic;



    QThread * m_pThread;

    ros::Subscriber sub_chess;

};
#endif
