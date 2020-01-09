#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
int main(int argc, char** argv)
{
  ros::init(argc, argv, "listener_tf");
  ros::NodeHandle n;
  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle = n.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv;
  add_turtle.call(srv);
  ros::Publisher turtle2_vel = n.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);
  tf::TransformListener listener;
  ros::Rate rate(10);
  while (n.ok())
  {
    tf::StampedTransform transform;
    try
    {
      listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);
      geometry_msgs::Twist vel_msg;
      double x = transform.getOrigin().x();
      double y = transform.getOrigin().y();
      vel_msg.linear.x = 0.5 * sqrt(x * x + y * y);
      vel_msg.angular.z = 4.0 * atan2(y, x);
      turtle2_vel.publish(vel_msg);
    }
    catch (tf::TransformException &ex)
    {
      ROS_ERROR("%s",ex.what());
    }
    rate.sleep();
  }
  return 0;
}
