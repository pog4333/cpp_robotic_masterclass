#include "../include/test_library/display_vel.h"
#include "display_vel.h"

void display_velocity(double linear, double angular) {
     
    double vel_lin = linear;
    double vel_ang = angular;
    std::cout << "velocity_linear: " << vel_lin << " velocity_anglar: " << vel_ang << std::endl;
     
}