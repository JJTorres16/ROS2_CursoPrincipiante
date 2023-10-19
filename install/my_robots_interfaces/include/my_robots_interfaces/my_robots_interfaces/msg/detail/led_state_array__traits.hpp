// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robots_interfaces:msg/LedStateArray.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__TRAITS_HPP_
#define MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robots_interfaces/msg/detail/led_state_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robots_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LedStateArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: array_of_leds
  {
    if (msg.array_of_leds.size() == 0) {
      out << "array_of_leds: []";
    } else {
      out << "array_of_leds: [";
      size_t pending_items = msg.array_of_leds.size();
      for (auto item : msg.array_of_leds) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LedStateArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: array_of_leds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.array_of_leds.size() == 0) {
      out << "array_of_leds: []\n";
    } else {
      out << "array_of_leds:\n";
      for (auto item : msg.array_of_leds) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LedStateArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_robots_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robots_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robots_interfaces::msg::LedStateArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robots_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robots_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robots_interfaces::msg::LedStateArray & msg)
{
  return my_robots_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robots_interfaces::msg::LedStateArray>()
{
  return "my_robots_interfaces::msg::LedStateArray";
}

template<>
inline const char * name<my_robots_interfaces::msg::LedStateArray>()
{
  return "my_robots_interfaces/msg/LedStateArray";
}

template<>
struct has_fixed_size<my_robots_interfaces::msg::LedStateArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robots_interfaces::msg::LedStateArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robots_interfaces::msg::LedStateArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__TRAITS_HPP_
