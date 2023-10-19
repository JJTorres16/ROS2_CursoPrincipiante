#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from example_interfaces.msg import String # Need to be added in the package.xml file


class RobotNewsStationNode(Node):
    def __init__(self):
        super().__init__("robot_news_station")
        self.declare_parameter("name_of_robot", "Huyang")
        self.robot_name = self.get_parameter("name_of_robot").value

        self.declare_parameter("amount_of_time", 0.5)
        self.time_for_timer_ = self.get_parameter("amount_of_time").value

        # Creating a publisher (msg_type, topic_name_where_to_publish, buffer_size)
        self.publisher_ = self.create_publisher(String, "robots_news", 10)

        # Making a timer
        self.timer_ = self.create_timer(self.time_for_timer_, self.publish_news)
        self.get_logger().info("Robots News Station has been started")

    # Function to publish
    # Every time this function is called, the publisher will publishe de message "msg" in
    # topic "robot_news"
    def publish_news(self):
        msg = String()
        msg.data = "Hello, this is " + str(self.robot_name) + " from the robot news station"
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()