from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    long_desc = LaunchDescription()

    robots_names = ["Chooper", "BB8", "Hyuang", "R2D2", "C3PO"]
    robots_news_station_nodes = []

    for name in robots_names:
        robots_news_station_nodes.append(Node(
            package="my_py_pkg",
            executable="robot_news_station",
            name="robots_news_station_" + name.lower(),
            parameters=[
                {"name_of_robot": name},
                {"amount_of_time": 5.0}
            ]
        ))

    smartphone_node = Node (
        package="my_py_pkg",
        executable="smartphone",
        name="smartphone"
    )

    for node in robots_news_station_nodes:
        long_desc.add_action(node)

    long_desc.add_action(smartphone_node)

    return long_desc
    

    

