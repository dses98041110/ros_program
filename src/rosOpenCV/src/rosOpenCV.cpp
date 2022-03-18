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



using namespace sl;
cv::Mat slMat2cvMat(Mat& input);
#ifdef HAVE_CUDA
cv::cuda::GpuMat slMat2cvMatGPU(Mat& input);


#endif // HAVE_CUDA

void printHelp();
void onMouse(int evt, int x, int y, int flags, void* param);
void imageSubtract(cv::Mat &image1, cv::Mat &image2);
std_msgs::String str_chess_position;
std::stringstream ss;
int main(int argc, char** argv)
{
		ros::init(argc, argv, "image_publisher");
		ros::NodeHandle nh;
		ros::Publisher pub_chess = nh.advertise<std_msgs::String>("chess_position", 5);  



		// Create a ZED camera object
		Camera zed;

		// Set configuration parameters
		InitParameters init_params;
		init_params.camera_resolution = RESOLUTION::HD720;
		init_params.depth_mode = DEPTH_MODE::ULTRA;
		init_params.coordinate_units = UNIT::METER;
		if (argc > 1) init_params.input.setFromSVOFile(argv[1]);

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
		cv::Rect rect(257,40,202,202);
		cv::Mat result=image_ocv(rect);

		// Loop until 'q' is pressed
		char key = ' ';
		cv::Point2i pt(-1,-1);//assume initial point
		//cv::namedWindow("Image");
		//cv::setMouseCallback("Image", onMouse, (void*)&pt);
		zed.grab(runtime_parameters);
		zed.retrieveImage(image_zed, VIEW::LEFT, MEM::CPU, new_image_size);
		cv::Mat before;
		cv::Mat after;
		result.copyTo(before);
		cv::imshow("before",result);



		while (key != 'q') {

			if (zed.grab(runtime_parameters) == ERROR_CODE::SUCCESS) {
			    
			    // Retrieve the left image, depth image in half-resolution



			    // Display image and depth using cv:Mat which share sl:Mat data
			    //cv::imshow("Image", image_ocv);


			    // Handle key event
			    //std::cout<<pt.x<<'\t'<<pt.y<<std::endl; 
			    
			    //processKeyEvent(zed, key);
				if(key=='b'){

					zed.retrieveImage(image_zed, VIEW::LEFT, MEM::CPU, new_image_size);	   
					result.copyTo(after);

					cv::imshow("before",before);
					cv::imshow("after",after);
					imageSubtract(before,after);
					after.copyTo(before);
				        pub_chess.publish(str_chess_position);		
				}

			}
			key = cv::waitKey(10);

		}
	

	zed.close();
	ros::spin();	
	return 0;
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
    }
}

void imageSubtract(cv::Mat &image1, cv::Mat &image2)
{
	ss.str("");
	ss.clear();

	cv::Mat image1_gary, image2_gary;
	if (image1.channels() != 1)
	{
		cv::cvtColor(image1, image1_gary, cv::COLOR_BGR2GRAY);
	}
	if (image2.channels() != 1)
	{
		cv::cvtColor(image2, image2_gary, cv::COLOR_BGR2GRAY);
	}

	cv::Mat frameDifference, absFrameDifferece;
	cv::Mat previousGrayFrame = image2_gary.clone();
	//图1减图2
	cv::subtract(image1_gary, image2_gary, frameDifference, cv::Mat(), CV_16SC1);

	//取绝对值
	absFrameDifferece = cv::abs(frameDifference);
	//位深的改变
	absFrameDifferece.convertTo(absFrameDifferece, CV_8UC1, 1, 0);
	cv::imshow("absFrameDifferece", absFrameDifferece);
	cv::Mat segmentation;
	
	//阈值处理（这一步很关键，要调好二值化的值）
	cv::threshold(absFrameDifferece, segmentation,50, 255, cv::THRESH_BINARY);
	//中值滤波
	cv::medianBlur(segmentation, segmentation, 3);

	//形态学处理(开闭运算)
	//形态学处理用到的算子
	cv::Mat morphologyKernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
	cv::morphologyEx(segmentation, segmentation, cv::MORPH_CLOSE, morphologyKernel, cv::Point(-1, -1), 2, cv::BORDER_REPLICATE);

	//显示二值化图片
	cv::imshow("segmentation", segmentation);

	//找边界
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

		//cv::approxPolyDP(cv::Mat(contours[index]), contours_poly[index], 3, true);
		//cv::Rect rect = cv::boundingRect(cv::Mat(contours_poly[index]));
		//cv::rectangle(image2, rect, cv::Scalar(0, 255, 0), 2);
		mu[index]=cv::moments(contours[index],false);
		mc[index] = cv::Point2f(mu[index].m10 / mu[index].m00, mu[index].m01 / mu[index].m00);
		int range;
		for(range=25;range<=200;range+=25){
			if(mc[index].x<=range){
				ss<<(char)(64+(range/25));
				break;
			}
		}
		for(range=25;range<=200;range+=25){
			if(mc[index].y<=range){
				ss<<(char)(48+(range/25));
				break;
			}
		}
		cv::circle(move, mc[index], 4, cv::Scalar(0, 255, 0), -1, 8, 0);
		str_chess_position.data=ss.str();

	}
        ROS_INFO("%s", str_chess_position.data.c_str()); 
	cv::imshow("move", move);
}

