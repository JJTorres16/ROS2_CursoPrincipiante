#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64
from example_interfaces.srv import SetBool

class NumberPublisherNode(Node):

    def __init__(self):
        super().__init__("number_counter")

        self.counter_ = 0

        # Making a suscriber 
        self.number_suscriber_ = self.create_subscription(Int64, 'number', 
                                                          self.callback_adding, 10)
        
         # Making a publisher
        self.counter_publisher_ = self.create_publisher(Int64, 'number_count', 10)                                         
        self.get_logger().info("Number Counter has been started")

        # Creating a server
        self.reset_counter_server_ = self.create_service(SetBool, "reset_counter",
                                                        self.callback_reset_count)


    def callback_adding(self, msg):
        self.counter_ += msg.data
        msg_counter = Int64()
        msg_counter.data = self.counter_
        self.counter_publisher_.publish(msg_counter)

    def callback_reset_count(self, request, response):
        if request.data:
            self.counter_ = -2
            response.success = True
            response.message = "Counter has been reset"
        else:
            response.success = False
            response.message = "Counter has not been reset"
            
        return response

        

def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
