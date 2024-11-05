#include "my_robot_manager/robot_manager.h"
#include "ros/forwards.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "iostream"
using namespace std;

int main(int argc, char **argv){
  ros::init(argc,argv,"robic_manager");
  ros::NodeHandle nh;
  const RobotManager robic = RobotManager(&nh, "/robot1/odom", "robic", "second");
  robic.print_specification();
  const RobotManager rubic =RobotManager(&nh, "/robot2/odom", "rubic", "second");
  rubic.print_specification();
  ros::spin(); 
}