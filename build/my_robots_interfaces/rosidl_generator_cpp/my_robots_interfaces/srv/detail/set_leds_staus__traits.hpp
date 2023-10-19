// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robots_interfaces:srv/SetLedsStaus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__TRAITS_HPP_
#define MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robots_interfaces/srv/detail/set_leds_staus__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robots_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetLedsStaus_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: led_1
  {
    out << "led_1: ";
    rosidl_generator_traits::value_to_yaml(msg.led_1, out);
    out << ", ";
  }

  // member: led_2
  {
    out << "led_2: ";
    rosidl_generator_traits::value_to_yaml(msg.led_2, out);
    out << ", ";
  }

  // member: led_3
  {
    out << "led_3: ";
    rosidl_generator_traits::value_to_yaml(msg.led_3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetLedsStaus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: led_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "led_1: ";
    rosidl_generator_traits::value_to_yaml(msg.led_1, out);
    out << "\n";
  }

  // member: led_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "led_2: ";
    rosidl_generator_traits::value_to_yaml(msg.led_2, out);
    out << "\n";
  }

  // member: led_3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "led_3: ";
    rosidl_generator_traits::value_to_yaml(msg.led_3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetLedsStaus_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_robots_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robots_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robots_interfaces::srv::SetLedsStaus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robots_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robots_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_robots_interfaces::srv::SetLedsStaus_Request & msg)
{
  return my_robots_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_robots_interfaces::srv::SetLedsStaus_Request>()
{
  return "my_robots_interfaces::srv::SetLedsStaus_Request";
}

template<>
inline const char * name<my_robots_interfaces::srv::SetLedsStaus_Request>()
{
  return "my_robots_interfaces/srv/SetLedsStaus_Request";
}

template<>
struct has_fixed_size<my_robots_interfaces::srv::SetLedsStaus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robots_interfaces::srv::SetLedsStaus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robots_interfaces::srv::SetLedsStaus_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_robots_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetLedsStaus_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetLedsStaus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetLedsStaus_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_robots_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robots_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robots_interfaces::srv::SetLedsStaus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robots_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robots_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_robots_interfaces::srv::SetLedsStaus_Response & msg)
{
  return my_robots_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_robots_interfaces::srv::SetLedsStaus_Response>()
{
  return "my_robots_interfaces::srv::SetLedsStaus_Response";
}

template<>
inline const char * name<my_robots_interfaces::srv::SetLedsStaus_Response>()
{
  return "my_robots_interfaces/srv/SetLedsStaus_Response";
}

template<>
struct has_fixed_size<my_robots_interfaces::srv::SetLedsStaus_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robots_interfaces::srv::SetLedsStaus_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robots_interfaces::srv::SetLedsStaus_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_robots_interfaces::srv::SetLedsStaus>()
{
  return "my_robots_interfaces::srv::SetLedsStaus";
}

template<>
inline const char * name<my_robots_interfaces::srv::SetLedsStaus>()
{
  return "my_robots_interfaces/srv/SetLedsStaus";
}

template<>
struct has_fixed_size<my_robots_interfaces::srv::SetLedsStaus>
  : std::integral_constant<
    bool,
    has_fixed_size<my_robots_interfaces::srv::SetLedsStaus_Request>::value &&
    has_fixed_size<my_robots_interfaces::srv::SetLedsStaus_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_robots_interfaces::srv::SetLedsStaus>
  : std::integral_constant<
    bool,
    has_bounded_size<my_robots_interfaces::srv::SetLedsStaus_Request>::value &&
    has_bounded_size<my_robots_interfaces::srv::SetLedsStaus_Response>::value
  >
{
};

template<>
struct is_service<my_robots_interfaces::srv::SetLedsStaus>
  : std::true_type
{
};

template<>
struct is_service_request<my_robots_interfaces::srv::SetLedsStaus_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_robots_interfaces::srv::SetLedsStaus_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__TRAITS_HPP_
