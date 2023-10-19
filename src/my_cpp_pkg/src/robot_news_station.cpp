#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp" // Extension .hpp for C++

class RobotNewsStationNode : public rclcpp::Node {

    public:
        // Constructor de la clase del nodo (nodes_name)  
        RobotNewsStationNode() : Node("robot_news_station")/*, robot_name_("Chooper")*/{ 
            // Iniatilizing the publisher (name_of_topic, buffer)
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robots_news", 10);
            timer_ = this->create_wall_timer(std::chrono::milliseconds(500), 
                                             std::bind(&RobotNewsStationNode::publishNews, this));
            RCLCPP_INFO(this->get_logger(), "Robots News Station has been Started");
            this->declare_parameter("name_of_robot", "Chooper");
            robot_name_ = this->get_parameter("name_of_robot").as_string();
        }

    private:
        void publishNews(){
            auto msg = example_interfaces::msg::String();
            msg.data = std::string("HI, this is ") + robot_name_ + std::string(" from the Ghost");
            publisher_->publish(msg);
        }

        // Declaring varibles
        std::string robot_name_;
        // Creating a publihser with Shared Pointer
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
        // Making timer
        rclcpp::TimerBase::SharedPtr timer_;
};

int main (int argc, char**argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}