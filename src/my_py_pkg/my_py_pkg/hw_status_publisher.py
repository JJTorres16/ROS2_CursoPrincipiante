#!/usr/bin/env pyhton3

import rclpy
from rclpy.node import Node
from my_robots_interfaces.msg import HardwareStatus

class HardwareStatusPublisherNode(Node):
    
    def __init__(self):
        super().__init__("hw_status_publisher")

        # Create a publisher
        self.hw_status_publisher_ = self.create_publisher(HardwareStatus,
                                                          "hardware_status", 10)
        
        # Create a timer
        self.timer_ = self.create_timer(1.0,self.publish_hw_status)

        # A logger
        self.get_logger().info("Hardware status publisher has been started")
        
    def publish_hw_status(self):
        msg = HardwareStatus()
        msg.temperature = 45
        msg.motors_are_ready = True
        msg.debug_message = "Nothing sepecial here"
        self.hw_status_publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()