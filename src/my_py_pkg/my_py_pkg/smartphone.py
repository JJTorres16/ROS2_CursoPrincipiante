#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from example_interfaces.msg import String


class SmarthponeNode(Node):
    def __init__(self):
        super().__init__("smartphone")
        
        # Making a suscriber (type, name_of_topic, callback_function, buffer)
        self.suscriber_ = self.create_subscription(String, "robots_news", 
                                                   self.callback_robot_news, 10)
        
        self.get_logger().info("Smartphone has been started.")

    def callback_robot_news(self, msg):
        self.get_logger().info(msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = SmarthponeNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()