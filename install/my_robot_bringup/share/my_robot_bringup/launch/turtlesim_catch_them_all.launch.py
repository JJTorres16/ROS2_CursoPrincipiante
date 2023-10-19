from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    launch_desc = LaunchDescription()

    # The three nodes we use
    turtlesim = Node(
        package="turtlesim",
        executable="turtlesim_node"
    )

    turtle_spawner_node = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_spawner",
        parameters=[
            {"spawn_frequency": 0.5}
        ]
    )

    turtle_controller_node = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_controller",
        parameters=[
            {"catch_closest_turtle": True}
        ]
    )

    launch_desc.add_action(turtlesim)
    launch_desc.add_action(turtle_spawner_node)
    launch_desc.add_action(turtle_controller_node)

    return launch_desc