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

    sub_chess = nh.subscribe(m_topic, 10, &RobotThread::poseCallback, this);
    pub_chess_group=nh.advertise<std_msgs::String>("chess_position_to_joint_position", 10);
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
    Q_EMIT closeGUI();
}

void RobotThread::pubPose(int current_position,int target_position,int category){
    QMutex * pMutex = new QMutex();
    pMutex->lock();
    ss.str("");
    ss<<(char)(65+7-(current_position%8));
    ss<<(char)(49+(current_position/8));
    ss<<category;
    ss<<1;
    
    str_chess_position.data=ss.str();
    ROS_INFO("pubPose: [%s]", str_chess_position.data.c_str());
    ss.str("");
    ss.clear();
    pub_chess_group.publish(str_chess_position);

    ss.str("");
    if(target_position==65){
      ss<<(char)(73);
      ss<<(char)(50);
    }
    else{
      ss<<(char)(65+7-(target_position%8));
      ss<<(char)(49+(target_position/8));
    }

    ss<<category;
    ss<<0;
    
    str_chess_position.data=ss.str();
    ROS_INFO("pubPose: [%s]", str_chess_position.data.c_str());
    ss.str("");
    ss.clear();
    pub_chess_group.publish(str_chess_position);
    pMutex->unlock();

    delete pMutex;
}
