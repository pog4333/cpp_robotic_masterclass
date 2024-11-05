#include "my_robot_manager/robot_manager.h"

void RobotManager::print_specification()const{
ROS_INFO("Robot_name = %s", robot_name.c_str());
ROS_INFO("Robot_model = %s", robot_model.c_str());
ROS_INFO("Battery_capacity = %f", battery_capacity_kwh);
ROS_INFO("Total_operation_hours = %d", total_operation_hours);
}