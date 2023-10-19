// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robots_interfaces:msg/Turtle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_
#define MY_ROBOTS_INTERFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robots_interfaces/msg/detail/turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robots_interfaces
{

namespace msg
{

namespace builder
{

class Init_Turtle_theta
{
public:
  explicit Init_Turtle_theta(::my_robots_interfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  ::my_robots_interfaces::msg::Turtle theta(::my_robots_interfaces::msg::Turtle::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robots_interfaces::msg::Turtle msg_;
};

class Init_Turtle_y
{
public:
  explicit Init_Turtle_y(::my_robots_interfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  Init_Turtle_theta y(::my_robots_interfaces::msg::Turtle::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Turtle_theta(msg_);
  }

private:
  ::my_robots_interfaces::msg::Turtle msg_;
};

class Init_Turtle_x
{
public:
  explicit Init_Turtle_x(::my_robots_interfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  Init_Turtle_y x(::my_robots_interfaces::msg::Turtle::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Turtle_y(msg_);
  }

private:
  ::my_robots_interfaces::msg::Turtle msg_;
};

class Init_Turtle_name_turtle
{
public:
  Init_Turtle_name_turtle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Turtle_x name_turtle(::my_robots_interfaces::msg::Turtle::_name_turtle_type arg)
  {
    msg_.name_turtle = std::move(arg);
    return Init_Turtle_x(msg_);
  }

private:
  ::my_robots_interfaces::msg::Turtle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robots_interfaces::msg::Turtle>()
{
  return my_robots_interfaces::msg::builder::Init_Turtle_name_turtle();
}

}  // namespace my_robots_interfaces

#endif  // MY_ROBOTS_INTERFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_
