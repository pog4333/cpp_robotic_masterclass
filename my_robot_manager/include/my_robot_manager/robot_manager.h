#pragma once
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "iostream"
#include <cmath>
#include <string>
#include "nav_msgs/Odometry.h"
#include "ros/service_server.h"
#include "ros/subscriber.h"
#include <std_srvs/Trigger.h>
using namespace std;

class RobotManager{


public:
  static int robot_count;
  RobotManager(ros::NodeHandle *nh, std::string topic, std::string name, std::string model);
  void print_specification()const;
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
  bool location_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res);
private:
  ros::ServiceServer service_location;
  float current_x_position;
  float current_y_position;
  ros::Subscriber odom_subscriber;
  std::string odom_topic;
  std::string robot_name, robot_model;
  float battery_capacity_kwh = 0.5;
  int total_operation_hours = 50;
};

