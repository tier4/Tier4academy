#include "ros/ros.h" //ROSで必要なヘッダー
#include "std_msgs/String.h"
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str()); //結果を標準出力
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "listener"); //ROS の初期化.ノードの名前を特定

  ros::NodeHandle n; //プロセスのノードへのハンドラを作成

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
 //rosmatserにchatterトピックを購読chatterCallback()を宣言
 //第1引数:購読するトピック名
 //第2引数:受信バッファの大きさ
 //第3引数:トピックデータ受信時に呼び出す関数
  ros::spin(); //待機ループ（メッセージの受信ごとにchatterCallbackを呼び出し）
  return 0;
}
