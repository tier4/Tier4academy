#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
int main(int argc, char** argv)
{
  ros::init(argc, argv, "add_broadcaster");
  ros::NodeHandle n;
  tf::TransformBroadcaster br;
  tf::Transform transform;
  ros::Rate rate(10);
  while (n.ok())
  {
    transform.setOrigin(tf::Vector3(1.0, 0.0, 0.0));
    transform.setRotation(tf::Quaternion(0.0, 0.0, 0.0, 1.0));
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "turtle1", "carrot1"));
    rate.sleep();
  }
  return 0;
}