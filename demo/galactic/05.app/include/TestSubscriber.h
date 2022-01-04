#include <chrono>
#include <cstdlib>
#include <memory>
 
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
class TestSubscriber : public rclcpp::Node {
public:
	TestSubscriber();
private:
	void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;

	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
}