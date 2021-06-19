
#include <chrono>
#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/path.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

using namespace std::chrono_literals;

class NavigationPublisher : public rclcpp::Node
{
public:

  //publisher constructor
  NavigationPublisher() : Node("publisher"), count_(0)
  {
    //Publisher creates it. Publish via the path_ellipse_partial topic
    publisher_ = this->create_publisher<nav_msgs::msg::Path>("path_ellipse_partial", 10);
    
    auto publish_msg = [this]() -> void {
      	auto message = nav_msgs::msg::Path();
  	nav_msgs::msg::Path path;
        geometry_msgs::msg::PoseStamped pose;
    
        pose.header.frame_id = "map";
        path.header.frame_id = "map";
        
        //It creates 136 different paths by scanning with 2 degree differences between 0-270 degrees. 
        for(int i=0;i<=270;i=i+2){
    	    pose.pose.position.x = 15*cos(i);
    	    pose.pose.position.y = 0.5*15*sin(i);
    	    pose.pose.position.z = 0;
    	    path.poses.push_back(pose);
    	    message = path;
    	    publisher_->publish(message); 
            
        }
    };
    
    //timer that allows the message to be publish periodically
    timer_ = this->create_wall_timer(1s, publish_msg);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NavigationPublisher>());
  rclcpp::shutdown();
  return 0;
}
