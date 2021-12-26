#include <ros/ros.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "hello_ros");

	ros::NodeHandle nh ;
	
	ROS_INFO_STREAM("hell ros") ;

	return 0 ;
}
