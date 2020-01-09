#include "ros/ros.h"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "simple");
  ros::NodeHandle n;
  ros::Rate loop_rate(1);
  int count = 0;
  while (ros::ok())
  {
    ROS_INFO("Hello %d", count++);
    loop_rate.sleep();
  }
  return 0;
}

