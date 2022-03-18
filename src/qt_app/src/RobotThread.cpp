#include "RobotThread.h"

RobotThread::RobotThread(int argc, char** pArgv, const char * topic)
    :	m_Init_argc(argc),
        m_pInit_argv(pArgv),
        m_topic(topic)
{/** Constructor for the robot thread **/}

RobotThread::~RobotThread()
{
    if (ros::isStarted())
    {
        ros::shutdown();
        ros::waitForShutdown();
    }//end if

    m_pThread->wait();
}//end destructor

bool RobotThread::init()
{
    m_pThread = new QThread();
    this->moveToThread(m_pThread);

    connect(m_pThread, &QThread::started, this, &RobotThread::run);
    ros::init(m_Init_argc, m_pInit_argv, "chess_game");

    if (!ros::master::check())
        return false;//do not start without ros.

    ros::start();
    ros::Time::init();
    ros::NodeHandle nh;

    sub_chess = nh.subscribe(m_topic, 10, &RobotThread::chatterCallback, this);

    m_pThread->start();
    return true;
}//set up the thread

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    QMutex * pMutex = new QMutex();

    pMutex->lock();
    ROS_INFO("I heard: [%s]", msg->data.c_str());
    pMutex->unlock();

    delete pMutex;

}//callback method to update the robot's position.

void RobotThread::run()
{
    ros::Rate loop_rate(100);
    QMutex * pMutex;
    while (ros::ok())
    {
        pMutex = new QMutex();


        pMutex->lock();
        

        pMutex->unlock();


        ros::spinOnce();
        loop_rate.sleep();
        delete pMutex;
    }//do ros things.
}
