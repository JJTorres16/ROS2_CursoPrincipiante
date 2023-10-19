// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robots_interfaces:srv/SetLedsStaus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__STRUCT_HPP_
#define MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Request __declspec(deprecated)
#endif

namespace my_robots_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetLedsStaus_Request_
{
  using Type = SetLedsStaus_Request_<ContainerAllocator>;

  explicit SetLedsStaus_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->led_1 = 0ll;
      this->led_2 = 0ll;
      this->led_3 = 0ll;
    }
  }

  explicit SetLedsStaus_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->led_1 = 0ll;
      this->led_2 = 0ll;
      this->led_3 = 0ll;
    }
  }

  // field types and members
  using _led_1_type =
    int64_t;
  _led_1_type led_1;
  using _led_2_type =
    int64_t;
  _led_2_type led_2;
  using _led_3_type =
    int64_t;
  _led_3_type led_3;

  // setters for named parameter idiom
  Type & set__led_1(
    const int64_t & _arg)
  {
    this->led_1 = _arg;
    return *this;
  }
  Type & set__led_2(
    const int64_t & _arg)
  {
    this->led_2 = _arg;
    return *this;
  }
  Type & set__led_3(
    const int64_t & _arg)
  {
    this->led_3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Request
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Request
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetLedsStaus_Request_ & other) const
  {
    if (this->led_1 != other.led_1) {
      return false;
    }
    if (this->led_2 != other.led_2) {
      return false;
    }
    if (this->led_3 != other.led_3) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetLedsStaus_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetLedsStaus_Request_

// alias to use template instance with default allocator
using SetLedsStaus_Request =
  my_robots_interfaces::srv::SetLedsStaus_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robots_interfaces


#ifndef _WIN32
# define DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Response __declspec(deprecated)
#endif

namespace my_robots_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetLedsStaus_Response_
{
  using Type = SetLedsStaus_Response_<ContainerAllocator>;

  explicit SetLedsStaus_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetLedsStaus_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Response
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robots_interfaces__srv__SetLedsStaus_Response
    std::shared_ptr<my_robots_interfaces::srv::SetLedsStaus_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetLedsStaus_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetLedsStaus_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetLedsStaus_Response_

// alias to use template instance with default allocator
using SetLedsStaus_Response =
  my_robots_interfaces::srv::SetLedsStaus_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robots_interfaces

namespace my_robots_interfaces
{

namespace srv
{

struct SetLedsStaus
{
  using Request = my_robots_interfaces::srv::SetLedsStaus_Request;
  using Response = my_robots_interfaces::srv::SetLedsStaus_Response;
};

}  // namespace srv

}  // namespace my_robots_interfaces

#endif  // MY_ROBOTS_INTERFACES__SRV__DETAIL__SET_LEDS_STAUS__STRUCT_HPP_
