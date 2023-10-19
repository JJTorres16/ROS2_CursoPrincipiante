// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robots_interfaces:srv/SetLedsStaus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__BUILDER_HPP_
#define MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robots_interfaces/srv/detail/set_leds_staus__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robots_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetLedsStaus_Request_led_3
{
public:
  explicit Init_SetLedsStaus_Request_led_3(::my_robots_interfaces::srv::SetLedsStaus_Request & msg)
  : msg_(msg)
  {}
  ::my_robots_interfaces::srv::SetLedsStaus_Request led_3(::my_robots_interfaces::srv::SetLedsStaus_Request::_led_3_type arg)
  {
    msg_.led_3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robots_interfaces::srv::SetLedsStaus_Request msg_;
};

class Init_SetLedsStaus_Request_led_2
{
public:
  explicit Init_SetLedsStaus_Request_led_2(::my_robots_interfaces::srv::SetLedsStaus_Request & msg)
  : msg_(msg)
  {}
  Init_SetLedsStaus_Request_led_3 led_2(::my_robots_interfaces::srv::SetLedsStaus_Request::_led_2_type arg)
  {
    msg_.led_2 = std::move(arg);
    return Init_SetLedsStaus_Request_led_3(msg_);
  }

private:
  ::my_robots_interfaces::srv::SetLedsStaus_Request msg_;
};

class Init_SetLedsStaus_Request_led_1
{
public:
  Init_SetLedsStaus_Request_led_1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetLedsStaus_Request_led_2 led_1(::my_robots_interfaces::srv::SetLedsStaus_Request::_led_1_type arg)
  {
    msg_.led_1 = std::move(arg);
    return Init_SetLedsStaus_Request_led_2(msg_);
  }

private:
  ::my_robots_interfaces::srv::SetLedsStaus_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robots_interfaces::srv::SetLedsStaus_Request>()
{
  return my_robots_interfaces::srv::builder::Init_SetLedsStaus_Request_led_1();
}

}  // namespace my_robots_interfaces


namespace my_robots_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetLedsStaus_Response_success
{
public:
  Init_SetLedsStaus_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robots_interfaces::srv::SetLedsStaus_Response success(::my_robots_interfaces::srv::SetLedsStaus_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robots_interfaces::srv::SetLedsStaus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robots_interfaces::srv::SetLedsStaus_Response>()
{
  return my_robots_interfaces::srv::builder::Init_SetLedsStaus_Response_success();
}

}  // namespace my_robots_interfaces

#endif  // MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__BUILDER_HPP_
