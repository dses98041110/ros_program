#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>


#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "std_msgs/String.h" 
 
 // ZED includes
#include <sl/Camera.hpp>


// OpenCV includes
#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

// OpenCV dep
#include <opencv2/cvconfig.h>
#include <opencv2/core/hal/interface.h>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/core/cvstd_wrapper.hpp>



using namespace sl;
cv::Mat slMat2cvMat(Mat& input);
#ifdef HAVE_CUDA
cv::cuda::GpuMat slMat2cvMatGPU(Mat& input);


#endif // HAVE_CUDA

void printHelp();
void onMouse(int evt, int x, int y, int flags, void* param);
void imageSubtract(cv::Mat &image1, cv::Mat &image2);
void chatterCallback(const std_msgs::String::ConstPtr& msg);

std_msgs::String str_chess_position;
std::stringstream ss;
std::map<std::string,int> map_chess_position;

Camera zed;
int state=0;
cv::Mat before;
cv::Mat after;

ros::Publisher pub_chess;
ros::Subscriber sub;
int main(int argc, char** argv)
{
		ros::init(argc, argv, "image_publisher");
		ros::NodeHandle nh;
		pub_chess = nh.advertise<std_msgs::String>("chess_position", 5); 
		sub = nh.subscribe("chatter", 1000, chatterCallback);

		// Create a ZED camera object


		// Set configuration parameters
		InitParameters init_params;
		init_params.camera_resolution = RESOLUTION::HD720;
		init_params.depth_mode = DEPTH_MODE::ULTRA;
		init_params.coordinate_units = UNIT::METER;
//		if (argc > 1) init_params.input.setFromSVOFile(argv[1]);

		// Open the camera
		ERROR_CODE err = zed.open(init_params);
		if (err != ERROR_CODE::SUCCESS) {
			printf("%s\n", toString(err).c_str());
			zed.close();
			return 1; // Quit if an error occurred
		}
		// Display help in console
		//printHelp();

		// Set runtime parameters after opening the camera
		RuntimeParameters runtime_parameters;
		runtime_parameters.sensing_mode = SENSING_MODE::STANDARD;

		// Prepare new image size to retrieve half-resolution images
		Resolution image_size = zed.getCameraInformation().camera_resolution;
		int new_width = image_size.width / 2;
		int new_height = image_size.height / 2;

		Resolution new_image_size(new_width, new_height);

		// To share data between sl::Mat and cv::Mat, use slMat2cvMat()
		// Only the headers and pointer to the sl::Mat are copied, not the data itself
		Mat image_zed(new_width, new_height, MAT_TYPE::U8_C4);
		cv::Mat image_ocv = slMat2cvMat(image_zed);
		cv::Rect rect(419,11,166,166);
		cv::Mat result=image_ocv(rect);

		// Loop until 'q' is pressed
		char key = ' ';
		cv::Point2i pt(-1,-1);//assume initial point

//		zed.grab(runtime_parameters);
//		zed.retrieveImage(image_zed, VIEW::LEFT, MEM::CPU, new_image_size);

//		result.copyTo(before);
//		cv::imshow("before",result);



		while (ros::ok()) {
			if (zed.grab(runtime_parameters) == ERROR_CODE::SUCCESS) {		  


//			    // Display image and depth using cv:Mat which share sl:Mat data
//			    zed.retrieveImage(image_zed, VIEW::LEFT, MEM::CPU, new_image_size);
//			    cv::namedWindow("Image");
//			    cv::setMouseCallback("Image", onMouse, (void*)&pt);
//			    cv::imshow("Image", image_ocv);



//			    

//				if(key=='b'){

//					zed.retrieveImage(image_zed, VIEW::LEFT, MEM::CPU, new_image_size);	   
//					result.copyTo(after);

//					cv::imshow("before",before);
//					cv::imshow("after",after);
//					imageSubtract(before,after);
//					after.copyTo(before);
//				        		
//				}

			}

			if(key == 'q'){
				break;
			}
			key = cv::waitKey(10);
			ros::spinOnce();	
		}
	

	zed.close();

	return 0;
}
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	// Prepare new image size to retrieve half-resolution images
	Resolution image_size = zed.getCameraInformation().camera_resolution;
	int new_width = image_size.width / 2;
	int new_height = image_size.height / 2;

	Resolution new_image_size(new_width, new_height);

	// To share data between sl::Mat and cv::Mat, use slMat2cvMat()
	// Only the headers and pointer to the sl::Mat are copied, not the data itself
	Mat image_zed(new_width, new_height, MAT_TYPE::U8_C4);
	cv::Mat image_ocv = slMat2cvMat(image_zed);
	cv::Rect rect(299,11,166,166);
	cv::Mat result=image_ocv(rect);
//	cv::Mat result=image_ocv;
	zed.retrieveImage(image_zed, VIEW::LEFT, MEM::CPU, new_image_size);
	ROS_INFO("I heard: [%s]", msg->data.c_str());
	if(state){
		cv::imshow("after",result);
		imageSubtract(before,result);	
		pub_chess.publish(str_chess_position);
		state=0;
	}
	else{
		result.copyTo(before);
		cv::imshow("before",before);
		state=1;
	}
	
}
// Mapping between MAT_TYPE and CV_TYPE
int getOCVtype(sl::MAT_TYPE type) {
    int cv_type = -1;
    switch (type) {
        case MAT_TYPE::F32_C1: cv_type = CV_32FC1; break;
        case MAT_TYPE::F32_C2: cv_type = CV_32FC2; break;
        case MAT_TYPE::F32_C3: cv_type = CV_32FC3; break;
        case MAT_TYPE::F32_C4: cv_type = CV_32FC4; break;
        case MAT_TYPE::U8_C1: cv_type = CV_8UC1; break;
        case MAT_TYPE::U8_C2: cv_type = CV_8UC2; break;
        case MAT_TYPE::U8_C3: cv_type = CV_8UC3; break;
        case MAT_TYPE::U8_C4: cv_type = CV_8UC4; break;
        default: break;
    }
    return cv_type;
}

/**
* Conversion function between sl::Mat and cv::Mat
**/
cv::Mat slMat2cvMat(Mat& input) {
    // Since cv::Mat data requires a uchar* pointer, we get the uchar1 pointer from sl::Mat (getPtr<T>())
    // cv::Mat and sl::Mat will share a single memory structure
    return cv::Mat(input.getHeight(), input.getWidth(), getOCVtype(input.getDataType()), input.getPtr<sl::uchar1>(MEM::CPU), input.getStepBytes(sl::MEM::CPU));
}

#ifdef HAVE_CUDA
/**
* Conversion function between sl::Mat and cv::Mat
**/
cv::cuda::GpuMat slMat2cvMatGPU(Mat& input) {
    // Since cv::Mat data requires a uchar* pointer, we get the uchar1 pointer from sl::Mat (getPtr<T>())
    // cv::Mat and sl::Mat will share a single memory structure
    return cv::cuda::GpuMat(input.getHeight(), input.getWidth(), getOCVtype(input.getDataType()), input.getPtr<sl::uchar1>(MEM::GPU), input.getStepBytes(sl::MEM::GPU));
}
#endif

/**
* This function displays help in console
**/
void printHelp() {
    std::cout << " Press 's' to save Side by side images" << std::endl;
    std::cout << " Press 'p' to save Point Cloud" << std::endl;
    std::cout << " Press 'd' to save Depth image" << std::endl;
    std::cout << " Press 'm' to switch Point Cloud format" << std::endl;
    std::cout << " Press 'n' to switch Depth format" << std::endl;
}

 void onMouse(int evt, int x, int y, int flags, void* param) {
    if(evt == cv::EVENT_LBUTTONDOWN) {
        cv::Point* ptPtr = (cv::Point*)param;
        ptPtr->x = x;
        ptPtr->y = y;
	std::cout<<x<<'\t'<<y<<std::endl; 	
    }
}

void imageSubtract(cv::Mat &image1, cv::Mat &image2)
{
	cv::Mat image1_gary, image2_gary,image1_equal,image2_equal;

	if (image1.channels() != 1)
	{
		cv::cvtColor(image1, image1_gary, cv::COLOR_BGR2GRAY);
    		GaussianBlur(image1_gary, image1_gary, cv::Size(3,3), 0);
	

	}
	if (image2.channels() != 1)
	{

		cv::cvtColor(image2, image2_gary, cv::COLOR_BGR2GRAY);
    		GaussianBlur(image2_gary, image2_gary, cv::Size(3,3), 0);
	}

	cv::Mat frameDifference, absFrameDifferece;


//	//图1减图2
//	cv::subtract(image1_gary, image2_gary, frameDifference, cv::Mat(), CV_16SC1);
//	cv::imshow("frameDifference", frameDifference);
//	//取绝对值
//	absFrameDifferece = cv::abs(frameDifference);

//	//位深的改变
//	absFrameDifferece.convertTo(absFrameDifferece, CV_8UC1, 1, 0);
//	cv::imshow("subtract", absFrameDifferece);

    	absdiff(image1_gary, image2_gary, absFrameDifferece);

	cv::imshow("diff", absFrameDifferece);


	cv::Mat segmentation;
//	
//	//阈值处理（这一步很关键，要调好二值化的值）
	cv::threshold(absFrameDifferece, segmentation,35, 255, cv::THRESH_BINARY);
//	cv::adaptiveThreshold( absFrameDifferece,segmentation, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 3, 0);

//	//中值滤波


	cv::imshow("threshold", segmentation);


//	//形态学处理(开闭运算)
//	//形态学处理用到的算子
	cv::Mat morphologyKernel;
	morphologyKernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3,3), cv::Point(-1, -1));
	erode(segmentation, segmentation,morphologyKernel,cv::Point(-1, -1), 2);
	cv::imshow("erode", segmentation);

	morphologyKernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3,3), cv::Point(-1, -1));
	dilate(segmentation, segmentation,morphologyKernel,cv::Point(-1, -1), 1);
	cv::imshow("dilate", segmentation);
//	cv::morphologyEx(segmentation, segmentation, cv::MORPH_OPEN, morphologyKernel, cv::Point(-1, -1), 1, cv::BORDER_REPLICATE);
//	cv::imshow("morphologyEx", segmentation);
////	//显示二值化图片


////	//找边界
	std::vector< std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(segmentation, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));//CV_RETR_TREE
	std::vector< std::vector<cv::Point> > contours_poly(contours.size());

	std::vector<cv::Rect> boundRect;
	boundRect.clear();
	std::vector<cv::Point2f> mc(contours.size());
	std::vector<cv::Moments> mu(contours.size());
	cv::Mat move;
	image1.copyTo(move);
	for (int index = 0; index < contours.size(); index++)
	{

		int area = contourArea(contours[index]);
		std::cout << area << std::endl;
		if(area<50||area>300){
			continue;
		}

		mu[index]=cv::moments(contours[index],false);
		mc[index] = cv::Point2f(mu[index].m10 / mu[index].m00, mu[index].m01 / mu[index].m00);
		ss<<(char)(73-(mc[index].y/20));
		ss<<(char)(57-(mc[index].x/20));
		str_chess_position.data=ss.str();
//		if(map_chess_position.count(ss.str())==0){
//			cv::circle(move, mc[index], 4, cv::Scalar(0, 255, 0), -1, 8, 0);
//			str_chess_position.data=ss.str();
//		}
	


	}
        ROS_INFO("%s", str_chess_position.data.c_str()); 
	cv::imshow("move", move);


}

