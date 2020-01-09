#include "ros/ros.h"
#include "tutorials/user.h"
#include <sstream>
int main(int argc, char **argv) {
  ros::init(argc, argv, "talker2");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<tutorials::user>("chatter", 1000);
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok()) {
    tutorials::user msg;
    std::stringstream ss;
    ss << "hello world";
    msg.data = ss.str();
    msg.num = count;
    count++;
    chatter_pub.publish(msg);
    loop_rate.sleep();
  }
  return 0;
}
