// #include <ros/ros.h>
#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

int main(){
    list<string> laser{"range_max","range_min","angle_max","angle_min"};
    auto start = laser.begin();
    advance(start, 2);
    cout << "third from start element " << *start;
    // std::cout << "\n first element" << start;
    auto last = laser.end();
    last = next(last, -3);
    cout << "\n third from last element " << *last;
}
