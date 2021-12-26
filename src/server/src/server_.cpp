#include<ros/ros.h>
#include<std_srvs/Empty.h> //声明请求和响应类型
#include<geometry_msgs/Twist.h>

bool forward = true ;
//服务的回调函数，工作室给response对象的数据成员赋值
bool toggleForward(std_srvs::Empty::Request &req,   std_srvs::Empty::Response &resp)
{
    forward = !forward ;
    ROS_INFO_STREAM("Now sending" << (forward ? "  forward" : "  rotate") << " commands") ;
    return true ;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pubvel_toggle") ;
    ros::NodeHandle nh ;

    //创建一个服务对象，实际上是该对象完成服务调用，建议局部名称，拒绝接受私有名称(~开头，解决方法略)
    //最后的参数是指向回调指针
    ros::ServiceServer server = nh.advertiseService("toggle_forward", &toggleForward) ;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000) ;

    ros::Rate rate(2) ;

    while (ros::ok())
    {
        geometry_msgs::Twist msg ;
        msg.linear.x = forward ? 1.0 : 0.0 ;
        msg.angular.z = forward ? 0.0 : 1.0 ;

        pub.publish(msg) ;
        ros::spinOnce() ;   //提供ROS控制权（回调函数）
        rate.sleep() ;
    }
    
    return 0 ;
}