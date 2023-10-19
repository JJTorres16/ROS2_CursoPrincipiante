#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class SmartphoneNode : public rclcpp::Node {

    public:
        SmartphoneNode() : Node("smartphone"){

           // Initialize the suscriber
           suscriber_ = this->create_subscription<example_interfaces::msg::String>("robots_news", 
                                                                            10, 
                                                                            std::bind(&SmartphoneNode::callbackRobotNews, this,
                                                                            std::placeholders::_1));
            RCLCPP_INFO(this->get_logger(), "Smartphone has been started"); 
        }
        
    private:
        // Callback function
        void callbackRobotNews(const example_interfaces::msg::String::SharedPtr msg){

            RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
        }

        // Making the suscriber
        rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr suscriber_;
};

int main(int argc, char**argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartphoneNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}