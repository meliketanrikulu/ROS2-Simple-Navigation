
#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/path.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("publisher"), count_(0)
  {
    publisher_ = this->create_publisher<nav_msgs::msg::Path>("topic", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    nav_msgs::msg::Path path;
    geometry_msgs::msg::PoseStamped pose;
    

    auto message = nav_msgs::msg::Path();
    
    pose.header.frame_id = "map";
    path.header.frame_id = "map";
    
    for(int i=0;i<=270;i=i+2){
    	pose.pose.position.x = 15*cos(i);
    	pose.pose.position.y = 0.5*15*sin(i);
    	pose.pose.position.z = 0;
    	path.poses.push_back(pose);
    	message = path;
    	publisher_->publish(message);
    	
    
    }
    
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
