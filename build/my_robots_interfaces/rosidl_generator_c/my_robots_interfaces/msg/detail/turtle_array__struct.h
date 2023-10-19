// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robots_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_
#define MY_ROBOTS_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'turtles'
#include "my_robots_interfaces/msg/detail/turtle__struct.h"

/// Struct defined in msg/TurtleArray in the package my_robots_interfaces.
typedef struct my_robots_interfaces__msg__TurtleArray
{
  my_robots_interfaces__msg__Turtle__Sequence turtles;
} my_robots_interfaces__msg__TurtleArray;

// Struct for a sequence of my_robots_interfaces__msg__TurtleArray.
typedef struct my_robots_interfaces__msg__TurtleArray__Sequence
{
  my_robots_interfaces__msg__TurtleArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robots_interfaces__msg__TurtleArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOTS_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_
