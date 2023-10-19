#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts
from functools import partial

class AddTwoIntsClientNode(Node):
    def __init__(self):
        super().__init__("add_two_ints_client")
        self.call_add_two_ints_server(10, 6)
        self.call_add_two_ints_server(10, 17)
        self.call_add_two_ints_server(10, -6)


    def call_add_two_ints_server(self, a, b):
        # Creating a serve (Type, server_name)
        client = self.create_client(AddTwoInts, "add_two_ints")
        while not client.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn("Waiting for Server Add Two Ints...")

        request = AddTwoInts.Request()
        request.a = a
        request.b = b

        future = client.call_async(request)
        # When the future es complete, call a callback function
        # Only declaring the function will send only the future objetc, but not the
        # variables. We use partial in order to add more parameter to the callback
        future.add_done_callback(partial(self.callback_call_add_two_ints, a=a, b=b))

    # Future only contents the response, but no requese
    # How do we now which request is for the response
    def callback_call_add_two_ints(self, future, a, b):
        try:
            response = future.result()
            self.get_logger().info(str(a) + " + " + str(b) + " = " + str(response.sum))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))

def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClientNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()


