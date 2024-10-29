#include <forward_list>
#include <iostream>
#include <iterator>
using namespace std;

int main(){
  forward_list<string> laser{"range_max","range_min","angle_max","angle_min"};
  auto front = laser.begin();
  advance(front,2);
  cout << *front << '\n';
  auto back =laser.end();
  next(back,-3);
  cout << *back << "\n";

}