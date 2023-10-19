// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robots_interfaces:msg/LedStateArray.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__STRUCT_H_
#define MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'array_of_leds'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/LedStateArray in the package my_robots_interfaces.
typedef struct my_robots_interfaces__msg__LedStateArray
{
  rosidl_runtime_c__int64__Sequence array_of_leds;
} my_robots_interfaces__msg__LedStateArray;

// Struct for a sequence of my_robots_interfaces__msg__LedStateArray.
typedef struct my_robots_interfaces__msg__LedStateArray__Sequence
{
  my_robots_interfaces__msg__LedStateArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robots_interfaces__msg__LedStateArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOTS_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__STRUCT_H_
