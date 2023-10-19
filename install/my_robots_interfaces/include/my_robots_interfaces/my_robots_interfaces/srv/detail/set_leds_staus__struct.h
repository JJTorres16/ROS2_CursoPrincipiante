// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robots_interfaces:srv/SetLedsStaus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__STRUCT_H_
#define MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetLedsStaus in the package my_robots_interfaces.
typedef struct my_robots_interfaces__srv__SetLedsStaus_Request
{
  int64_t led_1;
  int64_t led_2;
  int64_t led_3;
} my_robots_interfaces__srv__SetLedsStaus_Request;

// Struct for a sequence of my_robots_interfaces__srv__SetLedsStaus_Request.
typedef struct my_robots_interfaces__srv__SetLedsStaus_Request__Sequence
{
  my_robots_interfaces__srv__SetLedsStaus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robots_interfaces__srv__SetLedsStaus_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetLedsStaus in the package my_robots_interfaces.
typedef struct my_robots_interfaces__srv__SetLedsStaus_Response
{
  bool success;
} my_robots_interfaces__srv__SetLedsStaus_Response;

// Struct for a sequence of my_robots_interfaces__srv__SetLedsStaus_Response.
typedef struct my_robots_interfaces__srv__SetLedsStaus_Response__Sequence
{
  my_robots_interfaces__srv__SetLedsStaus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robots_interfaces__srv__SetLedsStaus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__STRUCT_H_
