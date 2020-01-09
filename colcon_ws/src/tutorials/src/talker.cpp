#include "ros/ros.h" //ROS で必要なヘッダー
#include "std_msgs/String.h" //ROSで利用する型
#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker"); //ROS の初期化.ノードの名前を特定
  ros::NodeHandle n; //プロセスのノードへのハンドラを作成
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000); 
  //rosmasterにstd_msgs/String型chatterトピックの配信を宣言
  //第1引数:配信するトピック名
  //第2引数:送信バッファの大きさ
  ros::Rate loop_rate(10); //ループ頻度を設定
  while (ros::ok()) { //Ctrl-C(SINGINTシグナル)を押すと ros::ok() が false を返却
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world ";
    msg.data = ss.str();
    chatter_pub.publish(msg); //メッセージを発信
    loop_rate.sleep(); //10Hzの発信が行えるように残り時間をスリープ
  }
  return 0;
}
