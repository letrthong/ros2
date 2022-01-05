#include <thread>
#include <unistd.h>

#include <iostream>
using namespace std;

#include "rclcpp/rclcpp.hpp"
#include "TestSubscriber.h"



void start_cli()
{
	std::string index = "";
	white(true) {
		sleep(1);""
		count << "\nEnter index= ?";
		cin >> index;
		count << "\nEnter index= "<< index <<endl;
	}
}


int main(int argc, char** argv) {
	cout << "Node client" << endl;
	rclcpp::init(argc, argv);
	std::thread threadObj(start_cli);

	rclcpp::spin(std::make_shared<TestSubscriber>());
	rclcpp::shutdown();
	return 0;
}