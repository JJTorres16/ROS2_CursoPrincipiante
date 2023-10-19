#!/usr/bin/env python3

# Line bellow is for making this file an executable

import rclpy
from rclpy.node import Node

# Using POO
class MyNode(Node):
    
    def __init__(self):
        super().__init__("py_test")
        self.counter_ = 0
        self.get_logger().info("Hello, I'm working with POO on ROS2!!!")
        self.create_timer(0.5, self.timer_callback) # create_timer(seconds, function_to_callback)

    # A callback function
    def timer_callback(self):
        self.counter_ += 1
        self.get_logger().info("Hello!! " + str(self.counter_))

def main(args=None):
    # Initilize the ROS2 communication
    rclpy.init(args=args)

    # Create an object of Node("name_of_node")
    node = MyNode()
    #node = Node("py_test")
    #node.get_logger().info("Hello, I'm working on ROS2")
    
    # rclpy.spin allows to mantain the programa alive
    rclpy.spin(node)
    
    # Shutdown the ROS2 communication
    rclpy.shutdown()

if __name__ == "__main__":
    main()