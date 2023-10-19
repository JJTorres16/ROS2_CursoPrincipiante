#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts

def main(args=None):
    rclpy.init()
    node = Node("add_two_ints_no_opp")

    # Create a client
    client = node.create_client(AddTwoInts, "add_two_ints")
    # Wait for the server
    while not client.wait_for_service(timeout_sec=1.0):
        node.get_logger().warn("Waiting for server Add Two Ints...")

    request = AddTwoInts.Request()
    request.a = 4
    request.b = 4

    future = client.call_async(request) # Here we save the response
    rclpy.spin_until_future_complete(node, future)

    try:
        response = future.result() 
        node.get_logger().info(str(request.a) + " + " + str(request.b) + " = " 
                               + str(response.sum))
    except Exception as e:
        node.get_logger().error("Service call failed %r" % (e,))

    rclpy.shutdown()