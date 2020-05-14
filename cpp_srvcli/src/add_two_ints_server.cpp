#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

#include <memory> //提供动态内存规划，allocator等操作

void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
		std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> 		 response){
	//在AddTwoInts定义中
	//Request为 int64 A, int64 B
	//Response为 int64 sum

	response->sum = request->a + request->b;
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request:\na: %ld" "b: %ld",
		request->a, request->b);
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back response: [%ld]", (long int)response->sum); 
}

int main(int argc, char **argv){

	rclcpp::init(argc, argv);

	//这里用来一个比较奇怪的方法创建node指针
	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");

	//定义service的回调函数add
	rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service = 
		node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", &add);


	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");

	rclcpp::spin(node);
	rclcpp::shutdown();

	return 0;
}