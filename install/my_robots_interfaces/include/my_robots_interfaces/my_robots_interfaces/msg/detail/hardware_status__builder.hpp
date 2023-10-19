// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robots_interfaces:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_
#define MY_ROBOTS_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robots_interfaces/msg/detail/hardware_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robots_interfaces
{

namespace msg
{

namespace builder
{

class Init_HardwareStatus_debug_message
{
public:
  explicit Init_HardwareStatus_debug_message(::my_robots_interfaces::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  ::my_robots_interfaces::msg::HardwareStatus debug_message(::my_robots_interfaces::msg::HardwareStatus::_debug_message_type arg)
  {
    msg_.debug_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robots_interfaces::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_motors_are_ready
{
public:
  explicit Init_HardwareStatus_motors_are_ready(::my_robots_interfaces::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_debug_message motors_are_ready(::my_robots_interfaces::msg::HardwareStatus::_motors_are_ready_type arg)
  {
    msg_.motors_are_ready = std::move(arg);
    return Init_HardwareStatus_debug_message(msg_);
  }

private:
  ::my_robots_interfaces::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_temperature
{
public:
  Init_HardwareStatus_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HardwareStatus_motors_are_ready temperature(::my_robots_interfaces::msg::HardwareStatus::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_HardwareStatus_motors_are_ready(msg_);
  }

private:
  ::my_robots_interfaces::msg::HardwareStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robots_interfaces::msg::HardwareStatus>()
{
  return my_robots_interfaces::msg::builder::Init_HardwareStatus_temperature();
}

}  // namespace my_robots_interfaces

#endif  // MY_ROBOTS_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_
