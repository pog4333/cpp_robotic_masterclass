#include "display_vel.h"
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "../../test_library/include/test_library/display_vel.h"


void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  
  double linear = msg->twist.twist.linear.x;
  double angular = msg->twist.twist.angular.z;
  ros::Duration(1).sleep();
  display_velocity(linear,angular);
  
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "odom_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);
  
  ros::spin();

  return 0;
}