#include <ros/ros.h>
#include <motion_decoder/image_converter.hpp>
#include <apriltag_ros/AprilTagDetectionArray.h>
#include <apriltag_ros/AprilTagDetection.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>


ImageConverter* ic;

class RosClass
{
public:
	RosClass();
	~RosClass();
	void apriltag_detection_callback(const apriltag_ros::AprilTagDetectionArray msg);
private:
	ros::NodeHandle nh_;
	ros::Subscriber apriltag_detection_sub_;  
};

RosClass::RosClass()
{
	//TODO: Add a subscriber to get the AprilTag detections The callback function skelton is given.
	apriltag_detection_sub_ = nh_.subscribe("/tag_detections", 1, &RosClass::apriltag_detection_callback, this);
	ros::spin();
	ros::Rate loop_rate(50);
	while(ros::ok()) {
		ros::spinOnce();
		loop_rate.sleep();
	}
}

RosClass::~RosClass()
{
	ROS_INFO("In destructor\n");
}
void RosClass::apriltag_detection_callback(const apriltag_ros::AprilTagDetectionArray msg)
{
	ROS_INFO("In subscribe\n");
	//TODO: Parse message and publish transforms as apriltag_tf and camera
  
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "image_converter");
	RosClass rosclass;

	ImageConverter converter;
	ic = &converter;
	ROS_INFO("In main\n");
	// ros::Rate loop_rate(50);
	// while(ros::ok()) {
	// 	ros::spinOnce();
	// 	loop_rate.sleep();
	// }
	return 0;
}
