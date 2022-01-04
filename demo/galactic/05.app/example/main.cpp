#include <iostream>
using namespace std;

#include "rclcpp/rclcpp.hpp"
#include "TestSubscriber.h"

int main(int argc, char** argv) {
	cout << "Node client" << endl;
	rclcpp::init(argc, argv);
	 
	rclcpp::spin(std::make_shared<TestSubscriber>());
	rclcpp::shutdown();
	return 0;
}