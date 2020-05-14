#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher() : Node("minimal_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("topic", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&MinimalPublisher::timer_callback, this) 
        );//std::bind调用的是类的非静态成员变量，所以第一个参数要加this来确定是哪一个实例。
    }

private:
    void timer_callback(){
        auto message = tutorial_interfaces::msg::Num();
        message.num = this->count_++;
        RCLCPP_INFO(this->get_logger(), "Publishing: %d", message.num);
        publisher_->publish(message);
    }

    rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;
};

int main(int argc, char **argv){

    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<MinimalPublisher>()); //调用构造函数，返回shared_ptr

    rclcpp::shutdown();

    return 0;
}