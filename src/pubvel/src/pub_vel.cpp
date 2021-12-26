#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "pub_node_cpp") ;

	ros::NodeHandle nh ;

	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000) ;

	srand(time(0)) ;
	ros::Rate rate(2) ;

	while(ros::ok())
	{
		geometry_msgs::Twist msg ;
		msg.linear.x = double(rand())/double(RAND_MAX) ;
		msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1 ;

		pub.publish(msg) ;

		ROS_INFO_STREAM("sending random velocity command ok:"
		<<"linear="<<msg.linear.x<<
		"angular="<<msg.angular.z) ;

		rate.sleep();	
	}

	return 0 ;
}
