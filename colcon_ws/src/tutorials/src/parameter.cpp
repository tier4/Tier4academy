#include "ros/ros.h"
int main(int argc, char **argv)
{
   ros::init(argc, argv, "parameter");
   ros::NodeHandle n;
   if (argc > 1) {
     ros::param::set("parameter_test", argv[1]);
   } else {
     std::string str;
     ros::param::get("parameter_test", str);
     ROS_INFO("parameter=%s", str.c_str());
   }
   return 0;
 }
