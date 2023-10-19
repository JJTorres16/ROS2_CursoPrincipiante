#!/usr/bin/env python3

import rclpy
import math
from rclpy.node import Node
# We need to include turtlesim Pose
from turtlesim.msg import Pose
# In order tu publish the new pose of the robot
from geometry_msgs.msg import Twist
from my_robots_interfaces.msg import TurtleArray
from my_robots_interfaces.srv import CatchTurtle
from functools import partial

class TurtleControllerNode(Node):
    
    def __init__(self):
        super().__init__("turtle_contoller_node")
        # Variables
        self.pose_ = None
        self.target_turtle_ = None
        self.target_x = None
        self.target_y = None
        self.target_turtle_name = None

        # Parameters
        self.declare_parameter("catch_closest_turtle", True)
        self.catch_closest_turtle = self.get_parameter("catch_closest_turtle").value
        
        # Now, since we need to know the current posisition of the turtle
        # we need no create a suscriber to suscribre the /turtle1/pose topic
        # the interface publish, among others, the x and y position
        self.turtle_pose_suscriber_ = self.create_subscription(Pose, "turtle1/pose",
                                                               self.callback_turtle_pose, 10)
        
        self.turtle_cmd_vel_publisher_ = self.create_publisher(Twist, 
                                                               "turtle1/cmd_vel", 10)
        
        self.turtle_alive_array_client = self.create_subscription(TurtleArray, 'alive_turtles',
                                                                  self.set_new_coordinates, 10)
        
        self.control_loop_timer = self.create_timer(0.01, 
                                                    self.control_loop)
        
        self.get_logger().info("Turtle Controller Node has been started.")

    def callback_turtle_pose(self, msg: Pose):
        self.pose_ = msg

    def set_new_coordinates(self, msg):
        if len(msg.turtles) > 0:
            if self.catch_closest_turtle:
                closest_turtle = None
                closest_turtle_distance = None

                for turtle in msg.turtles:
                    dist_x = turtle.x - self.pose_.x
                    dist_y = turtle.y - self.pose_.y
                    disance = math.sqrt(dist_x**2 + dist_y**2)
                    if closest_turtle == None or disance < closest_turtle_distance:
                        closest_turtle = turtle
                        closest_turtle_distance = disance
                    
                self.target_turtle_ = closest_turtle
                self.target_x = self.target_turtle_.x
                self.target_y = self.target_turtle_.y
                self.target_turtle_name = self.target_turtle_.name_turtle

            else:
                self.target_turtle_ = msg.turtles[0]
                self.target_x = self.target_turtle_.x
                self.target_y = self.target_turtle_.y
                self.target_turtle_name = self.target_turtle_.name_turtle
    
    def control_loop(self):
        if self.pose_ == None or self.target_turtle_ == None:
            return
     
        dist_x = self.target_x - self.pose_.x
        dist_y = self.target_y - self.pose_.y
        distance = math.sqrt(dist_x**2 + dist_y**2)  

        msg_position = Twist()

        if distance > 0.5:
            # position
            msg_position.linear.x = distance

            # orientation
            target_theta = math.atan2(dist_y, dist_x)
            diff_theta = target_theta - self.pose_.theta
            if diff_theta > math.pi:
                diff_theta -= 2*math.pi
            elif diff_theta < -math.pi:
                diff_theta += 2*math.pi

            msg_position.angular.z = 4*diff_theta

        else:
            msg_position.linear.x = 0.0
            msg_position.angular.z = 0.0
            self.call_catch_turtle_service(self.target_turtle_name)
            self.target_turtle_ = None

        self.turtle_cmd_vel_publisher_.publish(msg_position)

        
    def call_kill_client(self, target_turtle_name):
        self.kill_turtle_client = self.create_client(CatchTurtle, "catch_turtle")
        while not self.kill_turtle_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn("Waiting for Catch Turtle Service!!!...")

            catch_turtle_request_ = CatchTurtle.Request()
            catch_turtle_request_.turtle_name = target_turtle_name

            future = self.kill_turtle_client.call_async(catch_turtle_request_)
            future.add_done_callback(partial(self.callback_call_kill_client, target_turtle_name))

    def callback_call_kill_client(self, future, target_turtle_name):
        try:
            response = future.result()
        except Exception as e_:
            self.get_logger().error("Service call failed %r" % (e_,))

    def call_catch_turtle_service(self, turtle_name):
        catch_turtle_client = self.create_client(CatchTurtle, "catch_turtle")
        while not catch_turtle_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().warn("Waiting for Catch Turtle Service...")

        catch_turtle_request = CatchTurtle.Request()
        catch_turtle_request.turtle_name = turtle_name

        future = catch_turtle_client.call_async(catch_turtle_request)
        future.add_done_callback(partial(self.callback_call_catch_turtle, turtle_name=turtle_name))

    def callback_call_catch_turtle(self, future, turtle_name):
        try:
            response = future.result()
            if not response.success:
                self.get_logger().error("The turtle '" + str(turtle_name) + "' could not be caught")
        except Exception as e_:
            self.get_logger().error("Service call failed %r" % (e_,))

def main(args=None):
    rclpy.init()
    node = TurtleControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
