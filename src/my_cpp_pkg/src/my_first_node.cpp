#include "rclcpp/rclcpp.hpp"

// Using POO

class MyNode: public rclcpp::Node
{
public:
    MyNode(): Node("cpp_test"), counter_(0){
        RCLCPP_INFO(this->get_logger(), "Hello from ROS2 using C++");

        // Calling the timer function
        timer_ = this->create_wall_timer(std::chrono::seconds(1), 
                                         std::bind(&MyNode::timeCallback, this));
    }

private:

    void timeCallback(){
        counter_ ++;
        RCLCPP_INFO(this->get_logger(), "Hello %d", counter_);
    }

    // Function fo the timer with SharedPointer 
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;
};

int main(int argc, char **argv){

    // Initialize the ROS2 communication
    rclcpp::init(argc, argv);

    // Using shared pointer to create the node
    auto node = std::make_shared<MyNode>();
    //auto node = std::make_shared<rclcpp::Node>("cpp_test");
    //RCLCPP_INFO(node->get_logger(), "Hello from ROS2 using C++");

    // Using spin function
    rclcpp::spin(node);

    // Shutdown ROS2 communication
    rclcpp::shutdown();

    return 0;
}