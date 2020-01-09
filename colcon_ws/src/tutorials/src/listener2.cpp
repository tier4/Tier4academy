#include "ros/ros.h"
#include "tutorials/user.h"
void chatterCallback(const tutorials::user::ConstPtr& msg) {
    ROS_INFO("I heard: [%s][%d]", msg->data.c_str(), msg->num);
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "listener2");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::spin();
  return 0;
}
