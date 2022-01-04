#include "TestSubscriber.h"
#include "NodeDef.h"

TestSubscriber::TestSubscriber() : Node(NODE_NAME_TEST) {
	subscription_ = this->create_subscription<std_msgs::msg::String>(
		TOPIC_NAME_TEST , 10, std::bind(&TestSubscriber::topic_callback, this, _1));
}

void TestSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg) const {
	RCLCPP_INFO(this->get_logger(), "topic_callback: msg='%s'", msg->data.c_str());
}
