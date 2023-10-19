# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robots_interfaces:srv/SetLedsStaus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetLedsStaus_Request(type):
    """Metaclass of message 'SetLedsStaus_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_robots_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robots_interfaces.srv.SetLedsStaus_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_leds_staus__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_leds_staus__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_leds_staus__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_leds_staus__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_leds_staus__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetLedsStaus_Request(metaclass=Metaclass_SetLedsStaus_Request):
    """Message class 'SetLedsStaus_Request'."""

    __slots__ = [
        '_led_1',
        '_led_2',
        '_led_3',
    ]

    _fields_and_field_types = {
        'led_1': 'int64',
        'led_2': 'int64',
        'led_3': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.led_1 = kwargs.get('led_1', int())
        self.led_2 = kwargs.get('led_2', int())
        self.led_3 = kwargs.get('led_3', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.led_1 != other.led_1:
            return False
        if self.led_2 != other.led_2:
            return False
        if self.led_3 != other.led_3:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def led_1(self):
        """Message field 'led_1'."""
        return self._led_1

    @led_1.setter
    def led_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'led_1' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'led_1' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._led_1 = value

    @builtins.property
    def led_2(self):
        """Message field 'led_2'."""
        return self._led_2

    @led_2.setter
    def led_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'led_2' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'led_2' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._led_2 = value

    @builtins.property
    def led_3(self):
        """Message field 'led_3'."""
        return self._led_3

    @led_3.setter
    def led_3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'led_3' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'led_3' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._led_3 = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetLedsStaus_Response(type):
    """Metaclass of message 'SetLedsStaus_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_robots_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robots_interfaces.srv.SetLedsStaus_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_leds_staus__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_leds_staus__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_leds_staus__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_leds_staus__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_leds_staus__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetLedsStaus_Response(metaclass=Metaclass_SetLedsStaus_Response):
    """Message class 'SetLedsStaus_Response'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_SetLedsStaus(type):
    """Metaclass of service 'SetLedsStaus'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_robots_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robots_interfaces.srv.SetLedsStaus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_leds_staus

            from my_robots_interfaces.srv import _set_leds_staus
            if _set_leds_staus.Metaclass_SetLedsStaus_Request._TYPE_SUPPORT is None:
                _set_leds_staus.Metaclass_SetLedsStaus_Request.__import_type_support__()
            if _set_leds_staus.Metaclass_SetLedsStaus_Response._TYPE_SUPPORT is None:
                _set_leds_staus.Metaclass_SetLedsStaus_Response.__import_type_support__()


class SetLedsStaus(metaclass=Metaclass_SetLedsStaus):
    from my_robots_interfaces.srv._set_leds_staus import SetLedsStaus_Request as Request
    from my_robots_interfaces.srv._set_leds_staus import SetLedsStaus_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
