#!/usr/bin/env python3
import rclpy
import random
import math

from rclpy.node import Node
from turtlesim.srv import Spawn
from turtlesim.srv import Kill
from functools import partial
from my_robots_interfaces.msg import Turtle
from my_robots_interfaces.msg import TurtleArray
from my_robots_interfaces.srv import CatchTurtle

class TurtleSpawnerNode(Node):
    
    def __init__(self):
        super().__init__("turtle_spawner_node")
        # Create a counter
        self.turtle_counter_ = 1
        # Array of turtles alive
        self.array_turtles_alive = []

        # Parameters
        self.declare_parameter("spawn_frequency", 1.0)
        self.spawn_frequency = self.get_parameter("spawn_frequency").value

        # Create a timer. Every 100 ms
        self.timer_ = self.create_timer(1.0/self.spawn_frequency, 
                                        self.time_to_spawn_new_turtle)

        # Create a publisher
        self.turtle_alive_publisher_ = self.create_publisher(TurtleArray, 
                                                            "alive_turtles", 10)    
        
        # Create a servive when a Turtle is catched
        self.catch_turtle_service_ = self.create_service(CatchTurtle, "catch_turtle", 
                                                         self.callback_catch_turtle_service)

        # Logger for information
        self.get_logger().info("Turtle Spawner has been started!!!")
    
    def time_to_spawn_new_turtle(self):
        self.turtle_counter_ += 1
        
        random_x = round(random.uniform(1.00, 10.00), 2)
        random_y = round(random.uniform(1.00, 10.00), 2)
        random_theta = round(random.uniform(0.0, 2*math.pi), 2)
        turtle_name = "turtle_" + str(self.turtle_counter_)
        self.call_spawn_turtle(turtle_name, random_x, random_y, random_theta)
    
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

            turtle_alive_ = Turtle()
    
            # New turtle object
            turtle_alive_.x = x
            turtle_alive_.y = y
            turtle_alive_.theta = theta
            turtle_alive_.name_turtle = turtle_name
            # Adding to the array
            self.array_turtles_alive.append(turtle_alive_)
            self.publish_alive_turtle()

            if response.name != "":
                self.get_logger().info("New Turtle " + response.name + " has been spawn")
        except Exception as e_:
            self.get_logger().error()

    def publish_alive_turtle(self):
        turtle_array_msg_ = TurtleArray()
        turtle_array_msg_.turtles = self.array_turtles_alive
        self.turtle_alive_publisher_.publish(turtle_array_msg_)


    def callback_catch_turtle_service(self, request, response):
        self.call_kill_turtle(request.turtle_name)
        response.success = True

        return response

    def call_kill_turtle(self, turtle_name):
        kill_turtle_client = self.create_client(Kill, "kill")
        
        while not kill_turtle_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn("Waiting for Kill service...")

        kill_request_ = Kill.Request()
        kill_request_.name = turtle_name

        future = kill_turtle_client.call_async(kill_request_)
        future.add_done_callback(partial(self.callback_call_kill_turtle, turtle_name=turtle_name))

    def callback_call_kill_turtle(self, future, turtle_name):
        try:
            future.result()
            for (i, turtle) in enumerate(self.array_turtles_alive):
                if turtle.name_turtle == turtle_name:
                    del self.array_turtles_alive[i]
                    self.publish_alive_turtle()
                    break
        except Exception as e_:
            self.get_logger().error("Service call failed %r" % (e_,))


def main(args=None):
    rclpy.init()
    node = TurtleSpawnerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
