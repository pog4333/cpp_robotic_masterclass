#include "robot_commander/robot_commander.h"
#include "ros/duration.h"
#include <iostream>
#include <ros/ros.h>
#include <deque>
using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_vector");

  RobotCommander my_robot;

  // command the robot to keep going in circles
  my_robot.move_in_circles();

  int total_values;
  std::cout << "Enter the number of heading values that you want to capture: ";
  // get user input from the keyboard
  std::cin >> total_values;

  // INSERT YOUR CODE BELOW THIS LINE
  deque<float> headings;
  for(int i=0; i<total_values; i++){
    float last_heading = my_robot.get_heading();
    headings.push_front(last_heading);
    std::cout <<"\ncollecting heading value: "<<last_heading;
    ros::Duration(1.0).sleep();
  }
  int n = 0;
  for(const float& a : headings){
    std::cout <<"\nheading value "<< n <<" = "<< a;

  }
    

    
  // INSERT YOUR CODE ABOVE THIS LINE

  // stop the robot
  my_robot.stop_moving();
  

  return 0;
}