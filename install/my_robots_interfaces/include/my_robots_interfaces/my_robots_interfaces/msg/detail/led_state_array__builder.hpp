// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robots_interfaces:msg/LedStateArray.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_
#define MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robots_interfaces/msg/detail/led_state_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robots_interfaces
{

namespace msg
{

namespace builder
{

class Init_LedStateArray_array_of_leds
{
public:
  Init_LedStateArray_array_of_leds()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robots_interfaces::msg::LedStateArray array_of_leds(::my_robots_interfaces::msg::LedStateArray::_array_of_leds_type arg)
  {
    msg_.array_of_leds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robots_interfaces::msg::LedStateArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robots_interfaces::msg::LedStateArray>()
{
  return my_robots_interfaces::msg::builder::Init_LedStateArray_array_of_leds();
}

}  // namespace my_robots_interfaces

#endif  // MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_
