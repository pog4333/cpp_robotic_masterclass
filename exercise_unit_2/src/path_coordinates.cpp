#include "robot_commander/robot_commander.h"
#include <ros/ros.h>
#include <set>
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  ros::init(argc,argv,"path_cordinates");
  set<pair<float,float>> cordinates;
  RobotCommander my_robot;
  float x = my_robot.get_x_position();
  float y = my_robot.get_y_position();
  cordinates.insert(make_pair(x,y));
  my_robot.move_forward(1);
  x = my_robot.get_x_position();
  y = my_robot.get_y_position();
  cordinates.insert(make_pair(x,y));
  my_robot.turn(0.3, 2);
  x = my_robot.get_x_position();
  y = my_robot.get_y_position();
  cordinates.insert(make_pair(x,y));  
  my_robot.move_forward(4);
  x = my_robot.get_x_position();
 y = my_robot.get_y_position();
  cordinates.insert(make_pair(x,y));  
  my_robot.stop_moving();

  for (const auto& pos:cordinates){
  cout <<"x = " << pos.first << "y = "<< pos.second <<"\n"; }  
}