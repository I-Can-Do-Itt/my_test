#include<ros/ros.h>
#include<turtlesim/Spawn.h> //声明请求和响应类型

int main(int argc, char **argv)
{
    ros::init(argc, argv, "spawn_turtle") ;
    ros::NodeHandle nh ;

    //创建一个Client对象，实际上是该对喜完成服务调用
    ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn") ;

    //创建服务中的 请求(request)和响应对象(response)
    turtlesim::Spawn::Request req ;
    turtlesim::Spawn::Response resp ;

    //为请求的每一个域赋值，响应的值来自服务器节点，是接受的
    req.x = 2 ;
    req.y = 3 ;
    req.theta = M_PI/2 ;
    req.name = "Leo" ;

    //调用服务，成功返回true
    bool success = spawnClient.call(req, resp) ;

    if(success)
    {
        ROS_INFO_STREAM("Spawned a turtle named :" << resp.name) ;
    }
    else
    {
        ROS_INFO_STREAM("failed") ;
    }
    return 0 ;
}