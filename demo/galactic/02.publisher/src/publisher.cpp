#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include ""

using namespace std::chrono_literals;
//https://docs.ros.org/en/foxy/Tutorials/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html#write-the-subscriber-node

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */



typedef struct {
    int type,
    int data
} Foo;


class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher()
        : Node("minimal_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&MinimalPublisher::timer_callback, this));


        publisher1_= this->create_publisher< Foo>("status", 10);
        timer1_ = this->create_wall_timer(
            5000ms, std::bind(&MinimalPublisher::timer_callback1, this));
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Thong LT Hello, world! " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }


    void timer_callback1()
    {  
        Foo foo;
        foo.type = count_;
        foo.data = count_;
        publisher1_->publish(foo);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;


    rclcpp::TimerBase::SharedPtr timer1_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher1_;

    size_t count_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}