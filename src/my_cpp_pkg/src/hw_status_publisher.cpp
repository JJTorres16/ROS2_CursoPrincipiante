#include "rclcpp/rclcpp.hpp"
#include "my_robots_interfaces/msg/hardware_status.hpp"

class HardwareStatusPublisherNode : public rclcpp::Node {

    public:
        HardwareStatusPublisherNode() : Node("hw_status_publisher"){
            // Initialize the serever
            hw_status_publisher_ = this->create_publisher<my_robots_interfaces::msg::HardwareStatus>("hardware_status", 10);
            // Initialize the timer
            timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                             std::bind(&HardwareStatusPublisherNode::publish_hw_status, this));

            // Logger
            RCLCPP_INFO(this->get_logger(), "Hardware status publisher has been started");
        
        }

    private:
        void publish_hw_status(){
            auto msg = my_robots_interfaces::msg::HardwareStatus();
            msg.temperature = 45;
            msg.motors_are_ready = true;
            msg.debug_message = "Nothing special here";
            hw_status_publisher_->publish(msg);
        }

        // Creating a publihser with Shared Pointer
        rclcpp::Publisher<my_robots_interfaces::msg::HardwareStatus>::SharedPtr hw_status_publisher_;
        // Creating a timer
        rclcpp::TimerBase::SharedPtr timer_;

};

int main (int argc, char**argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HardwareStatusPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}



