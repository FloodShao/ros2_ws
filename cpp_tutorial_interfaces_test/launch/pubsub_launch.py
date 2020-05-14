from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
	return LaunchDescription([
		Node(
			package = 'cpp_tutorial_interfaces_test',
			node_namespace = 'publisher',
			node_executable = 'publisher',
			node_name = 'pub',
            output = "screen"
		),

		Node(
			package = 'cpp_tutorial_interfaces_test',
			node_namespace = 'subscriber',
			node_executable = 'subscriber',
			node_name = 'sub',
            output = "screen"
		)

	])