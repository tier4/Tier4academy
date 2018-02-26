#include "ros/ros.h"
#include "tutorials/AddNums.h"
#include <iostream>
int main(int argc, char **argv) {
  ros::init(argc, argv, "client");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<tutorials::AddNums>("add_nums");
  tutorials::AddNums srv;
  std::cout << "Input 2 nums:";
  std::cin >> srv.request.a >> srv.request.b;
  if (client.call(srv))
    ROS_INFO("Sum:%ld+%ld=%ld", srv.request.a, srv.request.b, srv.response.sum);
  else
    ROS_ERROR("Sum: Failed");
   return 0;
 }
