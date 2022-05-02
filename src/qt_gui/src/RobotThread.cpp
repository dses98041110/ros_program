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
    ros::init(m_Init_argc, m_pInit_argv, "ros_gui");

    if (!ros::master::check())
        return false;//do not start without ros.

    ros::start();
    ros::Time::init();
    ros::NodeHandle nh;

    sub_chess = nh.subscribe(m_topic, 10, &RobotThread::poseCallback, this);
    pub_chess_group=nh.advertise<std_msgs::String>("chatter", 10);
    m_pThread->start();
    return true;
}//set up the thread

void RobotThread::poseCallback(const std_msgs::String::ConstPtr& msg)
{
    QMutex * pMutex = new QMutex();

    pMutex->lock();
    ROS_INFO("I heard: [%s]", msg->data.c_str());
    std::string s(msg->data.c_str());

    Q_EMIT newPose(s[0]-65,s[1]-49,s[2]-65,s[3]-49);
    pMutex->unlock();

    delete pMutex;

}//callback method to update the robot's position.

void RobotThread::run()
{
    ros::Rate loop_rate(5);
    QMutex * pMutex;
    while (ros::ok())
    {
	//ROS_INFO("ok");
//        pMutex = new QMutex();
//        pMutex->lock();
//        

//        pMutex->unlock();


        ros::spinOnce();
        loop_rate.sleep();
        delete pMutex;
	
    }//do ros things.
}

void RobotThread::pubPose(){
    QMutex * pMutex = new QMutex();
    pMutex->lock();
    pub_chess_group.publish("placePiece");

    pMutex->unlock();

    delete pMutex;
}
