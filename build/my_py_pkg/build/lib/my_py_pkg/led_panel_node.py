#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from my_robots_interfaces.msg import LedStateArray
from my_robots_interfaces.srv import SetLedsStaus

class LedPanelNode(Node):
    
    def __init__(self):
        super().__init__("led_panel_node")
        self.led1_state = 0
        self.led2_state = 0
        self.led3_state = 0

        # Create a publisher
        self.led_status_publisher = self.create_publisher(LedStateArray,
                                                          "leds_status", 10)
        
        # Create a server
        self.led_status_server_ = self.create_service(SetLedsStaus, "set_led_status",
                                                      self.callback_set_led_status_server)
        
        # Create a timer
        self.timer_ = self.create_timer(5.0, self.publish_led_status)
        
        # Logger
        self.get_logger().info("Led Status node has been started")

    def publish_led_status(self):
        self.led_panel = LedStateArray()
        self.led_panel.array_of_leds = [self.led1_state, self.led2_state, self.led3_state]
        self.led_status_publisher.publish(self.led_panel)

    def callback_set_led_status_server(self, request, response):

        if request.led_1 not in [0, 1] or request.led_2 not in [0, 1] or request.led_3 not in [0, 1]:
            response.success = False
            self.get_logger().error("Error in data")
            return response
        else:
            response.success = True
            self.publish_led_status()

            self.led1_state = request.led_1
            self.led2_state = request.led_2
            self.led3_state = request.led_3
        
            return response

def main(args=None):
    rclpy.init()
    node = LedPanelNode()
    rclpy.spin(node)
    rclpy.shutdown

if __name__ == "__main__":
    main()