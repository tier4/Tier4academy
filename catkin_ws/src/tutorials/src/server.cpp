#include "ros/ros.h"
#include "tutorials/AddNums.h"
bool add(tutorials::AddNums::Request &req, tutorials::AddNums::Response &res)
{
  res.sum = req.a + req.b;
  return true;
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_nums", add);
  ros::spin();
  return 0;
}
