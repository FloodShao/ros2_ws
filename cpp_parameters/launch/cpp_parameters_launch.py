from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package = "cpp_parameters",
            node_executable = "parameter_node",
            node_name = "custom_parameter_node",
            output = "screen",
            emulate_tty = True,
            parameters = [
                {"my_parameter": "earth"}
            ]
        )

    ])