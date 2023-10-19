#!/usr/bin/env python3

import rclpy
import math
from rclpy.node import Node
# We need to include turtlesim Pose
from turtlesim.msg import Pose
# In order tu publish the new pose of the robot
from geometry_msgs.msg import Twist

class TurtleControllerNode(Node):
    
    def __init__(self):
        super().__init__("turtle_contoller_node")
        self.target_x = 4.0
        self.target_y = 8.0
        self.pose_ = None
        # Now, since we need to know the current posisition of the turtle
        # we need no create a suscriber to suscribre the /turtle1/pose topic
        # the interface publish, among others, the x and y position
        self.turtle_pose_suscriber_ = self.create_subscription(Pose, "turtle1/pose",
                                                               self.callback_turtle_pose, 10)
        
        self.turtle_cmd_vel_publisher_ = self.create_publisher(Twist, 
                                                               "turtle1/cmd_vel", 10)
        self.control_loop_timer = self.create_timer(0.01, 
                                                    self.control_loop)
        
        self.get_logger().info("Turtle Controller Node has been started.")

    def callback_turtle_pose(self, msg: Pose):
        self.pose_ = msg
        #self.get_logger().info("Posición de la tortuga x: " + str(msg.y) + ", y: " + str(msg.y))

    def control_loop(self):
        if self.pose_ == None:
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

        self.turtle_cmd_vel_publisher_.publish(msg_position)


def main(args=None):
    rclpy.init()
    node = TurtleControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()