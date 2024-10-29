#include "robot_commander/robot_commander.h"
#include "ros/init.h"
#include <iostream>

int main(int argc, char **argv){
    ros::init(argc, argv, "position_array");
    RobotCommander my_robot;
    float robot_pose[3];
    robot_pose[0] = my_robot.get_x_position();
    robot_pose[1] = my_robot.get_y_position();
    robot_pose[2] = my_robot.get_z_position();
    for (int i = 0; i < 3; i++)
      std::cout << robot_pose[i] << " ";
      std::cout << std::endl;
    
    return 0;
}