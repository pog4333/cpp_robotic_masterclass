#include "../include/test_library/test_library.h"

void display_pos(float linear_x, float angular_z) {
     
    float velocity_linear_x = linear_x;
    float velocity_angular_Z = angular_z;
    std::cout << "Velocity linear x: " << velocity_linear_x << " Velocity angular z: " << velocity_angular_Z << std::endl;
     
}