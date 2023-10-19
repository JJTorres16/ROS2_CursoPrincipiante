#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from my_robots_interfaces.srv import SetLedsStaus
from functools import partial

class BatteryStatusNode(Node):

    def __init__(self):
        super().__init__("battery_status_node")
        self.battery_state_ = "full" # The current state of battery
        self.last_time_battery_state_changed_ = self.get_current_time_seconds()
        self.battery_timer_ = self.create_timer(0.1, self.check_battery_state)

        self.get_logger().info("Battery node has been started")

    def check_battery_state(self):
        time_now = self.get_current_time_seconds()
        if self.battery_state_ == "full":
            if time_now - self.last_time_battery_state_changed_ > 4.0:
                self.battery_state_ = "empty"
                self.get_logger().info("Batter is empty! Charging battery")
                self.last_time_battery_state_changed_ = time_now
                self.call_set_led_status_server(0, 0, 1)
        else:
            if time_now - self.last_time_battery_state_changed_ > 6.0:
                self.battery_state_ = "full"
                self.get_logger().info("Battery is full again")
                self.last_time_battery_state_changed_ = time_now
                self.call_set_led_status_server(0, 0, 0)

    def get_current_time_seconds(self):
        secs, nsecs = self.get_clock().now().seconds_nanoseconds()
        return secs + nsecs/100000000.0

    def call_set_led_status_server(self, led_1, led_2, led_3):
        # Create a client
        led_status_client = self.create_client(SetLedsStaus, "set_led_status")
        # Wait for a conection
        while not led_status_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn("Wating for a conection...")

        request = SetLedsStaus.Request()
        request.led_1 = led_1
        request.led_2 = led_2
        request.led_3 = led_3

        future = led_status_client.call_async(request)
        future.add_done_callback(partial(self.callback_set_led_status, led_1=led_1, led_2=led_2, led_3=led_3))

    def callback_set_led_status(self, future, led_1, led_2, led_3):
        try:
            response = future.result()
            self.get_logger().info(str(response.success))
            self.get_logger().info("\nLed 1 state: " + str(led_1) + 
                               "\nLed 2 state: " + str(led_2) + 
                               "\nLed 3 state: " + str(led_3))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))

def main(args=None):
    rclpy.init()
    node = BatteryStatusNode()
    rclpy.spin(node)
    rclpy.shutdown()
