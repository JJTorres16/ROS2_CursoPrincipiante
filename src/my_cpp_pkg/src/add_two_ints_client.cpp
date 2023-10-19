#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoIntsClient : public rclcpp::Node{

    public:
        AddTwoIntsClient() : Node("add_two_ints_client"){ // (node_name)

            // Run the function 'callAddTwoIntService()' in the new thread
            // In the server code we use std::placeholders::_1 and std::placeholders::_2
            // Thanks to that, we can pass the parameters '1' and '4' in the next std::thred()
            //thread_1 = std::thread(std::bind(&AddTwoIntsClient::callAddTwoIntsService, this, 1, 4));

            // If we want to make multiples calls, we implement a thread pool
            threads_.push_back(std::thread(std::bind(&AddTwoIntsClient::callAddTwoIntsService, this, 1, 4)));
            threads_.push_back(std::thread(std::bind(&AddTwoIntsClient::callAddTwoIntsService, this, 5, 9)));
            threads_.push_back(std::thread(std::bind(&AddTwoIntsClient::callAddTwoIntsService, this, -2, -4)));

        }

        void callAddTwoIntsService(int a, int b){
            // Create the client
            auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
            // Wait for the server to be up
            while(!client->wait_for_service(std::chrono::seconds(1))){
                RCLCPP_WARN(this->get_logger(), "Waiting for the server to be up...");
            }

            // Create the requeste with shared point (request object)
            auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
            request->a = a;
            request->b = b;

            // Asynchronous communication
            auto future = client->async_send_request(request);

            // future.get() will wait for a response and pause the program. Can throw an exception
            try{
                auto response = future.get();
                RCLCPP_INFO(this->get_logger(), "%d + %d = %ld", a, b, response->sum);

            } catch (const std::exception &e) {
                RCLCPP_ERROR(this->get_logger(), "Service call failed");

            }               
        }
        
    private:
        // Create a new thread as member of the class
        //std::thread thread_1;
        std::vector<std::thread> threads_;

};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsClient>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}