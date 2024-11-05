#include "my_robot_manager/robot_manager.h"
#include "std_srvs/Trigger.h"
int RobotManager::robot_count=0;
RobotManager::RobotManager(ros::NodeHandle *nh, std::string topic, std::string name, std::string model){
odom_topic = topic;
robot_name = name;
robot_model = model;
robot_count++;
odom_subscriber = nh->subscribe(odom_topic, 1000, &RobotManager::odom_callback, this); 
service_location = nh->advertiseService(robot_name + "/log_current_position", &RobotManager::location_callback, this);
}
void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){
// ROS_INFO("%s position (x,y): %lf , %lf", robot_name.c_str(), msg->pose.pose.position.x, msg->pose.pose.position.y);
RobotManager::current_x_position = msg->pose.pose.position.x;
RobotManager::current_y_position = msg->pose.pose.position.y;  
}
bool RobotManager::location_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res ){

res.success = true;
res.message = "position logged";
return true;
}

void RobotManager::print_specification()const{
ROS_INFO("Robot_name = %s", robot_name.c_str());
ROS_INFO("Robot_model = %s", robot_model.c_str());
ROS_INFO("Battery_capacity = %f", battery_capacity_kwh);
ROS_INFO("Total_operation_hours = %d", total_operation_hours);
ROS_INFO("Robot count = %d",robot_count);
}