#include "robot_commander/robot_commander.h"
#include "ros/duration.h"
#include <ros/ros.h>
#include <vector>
#include <iostream>
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
  vector<float> headings;
  for(float i=0; i < total_values; i++){
    float last_heading = my_robot.get_heading();
    std::cout <<"\ncollecting heading value: "<< last_heading << " " ;
    headings.push_back(last_heading);
    ros::Duration(1.0).sleep();} 
  std::cout <<"\nheadings collected = ";    
  int n = 0; 
  for(const float& a : headings){
  std::cout <<"\n heading value "<< n <<" = "<< a;
  n++;}
    

    
  // INSERT YOUR CODE ABOVE THIS LINE

  // stop the robot
  my_robot.stop_moving();

  return 0;
}
