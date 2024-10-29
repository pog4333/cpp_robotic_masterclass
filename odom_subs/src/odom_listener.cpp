#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "../../test_library/include/test_library/test_library.h"


void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  
  float velocity_linear_x = msg->twist.twist.linear.x;
  float velocity_angular_z = msg->twist.twist.angular.z;
  ros::Duration(1).sleep();
  display_pos(velocity_linear_x,velocity_angular_z);
  
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "odom_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);
  
  ros::spin();

  return 0;
}