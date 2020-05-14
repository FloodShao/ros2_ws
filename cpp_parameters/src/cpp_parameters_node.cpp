#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <memory>
#include <functional>
#include <string>


using namespace std::chrono_literals;

class ParameterClass : public rclcpp::Node
{
public:
    ParameterClass() : Node("parameter_node")
    {
        this->declare_parameter<std::string>("my_parameter", "world"); //set the parameter with default string "world"
        timer_ = this->create_wall_timer(1000ms, std::bind(&ParameterClass::respond, this)); //trigger bind function for a 1000ms timer
    }

    void respond(){
        this->get_parameter("my_parameter", parameter_string_);
        RCLCPP_INFO(this->get_logger(), "Hello %s", parameter_string_.c_str());
    }

private:
    std::string parameter_string_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ParameterClass>());

    rclcpp::shutdown();

    return 0;
}