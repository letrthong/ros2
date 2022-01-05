#include <thread>
#include <unistd.h>

#include <iostream>
using namespace std;

#include "rclcpp/rclcpp.hpp"
#include "TestSubscriber.h"
#include "NodeClientServices.h"
#include "NodeClientAction.h"

void helper() {
	cout << "index= 0 -> getNavInfo" << endl;
	cout << "index= 1 -> sendRequest" << endl;
}
void start_cli()
{
	cout << "start_cli" <<endl;
	std::string index = "";
	NodeClientServices nodeClientServices;
	NodeClientAction   nodeClientAction;
	while(true) {
		sleep(1); 
		cout << "\nEnter index= ?";
		cin >> index;
		cout << "\nEnter index= "<< index <<endl;

		if (index == "0") {
			nodeClientServices.getNavInfo();
		}
		else if (index == "1") {
			nodeClientAction.sendRequest();
		}
		else {
			helper()
		}
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