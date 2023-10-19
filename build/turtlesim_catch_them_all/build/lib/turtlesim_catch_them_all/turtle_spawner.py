#!/usr/bin/env python3
import rclpy
import random
import math

from rclpy.node import Node
from turtlesim.srv import Spawn
from functools import partial


class TurtleSpawnerNode(Node):
    
    def __init__(self):
        super().__init__("turtle_spawner_node")
        # Create a counter
        self.turtle_counter_ = 1
        # Array of turtles alive
        self.array_turtles_alive = []

        # Create a timer. Every 100 ms
        '''self.last_time_turtle_spawned_ = self.get_current_time_seconds()
        self.timer_ = self.create_timer(0.01, self.time_to_spawn_new_turtle)'''
        self.timer_ = self.create_timer(5.0, self.time_to_spawn_new_turtle)

        # Create a publisher
        self.turtle_alive_list_publisher_ = self.create_publisher()

        # Logger for information
        self.get_logger().info("Turtle Spawner has been started!!!")

    '''def time_to_spawn_new_turtle(self):
        time_now = self.get_current_time_seconds()

        if time_now - self.last_time_turtle_spawned_ > 5.0:            
            #self.get_logger().info("New Turtle has been spawned")
            self.last_time_turtle_spawned_ = time_now
            #random numbers
            random_x = round(random.uniform(1.00, 10.00), 2)
            random_y = round(random.uniform(1.00, 10.00), 2)
            self.call_spawn_turtle(random_x, random_y, 0.0)'''
    
    def time_to_spawn_new_turtle(self):
        self.turtle_counter_ += 1
        
        random_x = round(random.uniform(1.00, 10.00), 2)
        random_y = round(random.uniform(1.00, 10.00), 2)
        random_theta = round(random.uniform(0.0, 2*math.pi), 2)
        turtle_name = "turtle_" + str(self.turtle_counter_)
        self.call_spawn_turtle(turtle_name, random_x, random_y, random_theta)

    '''def get_current_time_seconds(self):
        secs, nsecs = self.get_clock().now().seconds_nanoseconds()
        return secs + nsecs/100000000.0'''
    
    def call_spawn_turtle(self, turtle_name, x, y, theta):
        # Create a client 
        turtle_spawner_client_ = self.create_client(Spawn, "spawn")
        while not turtle_spawner_client_.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn("Waiting for server Spawn...")

        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = turtle_name

        future = turtle_spawner_client_.call_async(request)
        future.add_done_callback(partial(self.callback_call_spawn_turtle, turtle_name=turtle_name, x=x, y=y, theta=theta))

    def callback_call_spawn_turtle(self, future, turtle_name, x, y, theta):
        try:
            response = future.result()
            if response.name != "":
                self.get_logger().info("New Turtle " + response.name + " has been spawn")
        except Exception as e_:
            self.get_logger().error()


def main(args=None):
    rclpy.init()
    node = TurtleSpawnerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
