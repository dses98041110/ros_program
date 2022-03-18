// Generated by gencpp from file iiwa_msgs/CartesianPlane.msg
// DO NOT EDIT!


#ifndef IIWA_MSGS_MESSAGE_CARTESIANPLANE_H
#define IIWA_MSGS_MESSAGE_CARTESIANPLANE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace iiwa_msgs
{
template <class ContainerAllocator>
struct CartesianPlane_
{
  typedef CartesianPlane_<ContainerAllocator> Type;

  CartesianPlane_()
    {
    }
  CartesianPlane_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }





// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(XY)
  #undef XY
#endif
#if defined(_WIN32) && defined(XZ)
  #undef XZ
#endif
#if defined(_WIN32) && defined(YZ)
  #undef YZ
#endif

  enum {
    XY = 1,
    XZ = 2,
    YZ = 3,
  };


  typedef boost::shared_ptr< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> const> ConstPtr;

}; // struct CartesianPlane_

typedef ::iiwa_msgs::CartesianPlane_<std::allocator<void> > CartesianPlane;

typedef boost::shared_ptr< ::iiwa_msgs::CartesianPlane > CartesianPlanePtr;
typedef boost::shared_ptr< ::iiwa_msgs::CartesianPlane const> CartesianPlaneConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::iiwa_msgs::CartesianPlane_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace iiwa_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "15617e8d13d4abd04145334685da37ba";
  }

  static const char* value(const ::iiwa_msgs::CartesianPlane_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x15617e8d13d4abd0ULL;
  static const uint64_t static_value2 = 0x4145334685da37baULL;
};

template<class ContainerAllocator>
struct DataType< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "iiwa_msgs/CartesianPlane";
  }

  static const char* value(const ::iiwa_msgs::CartesianPlane_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 XY = 1\n"
"int32 XZ = 2\n"
"int32 YZ = 3\n"
;
  }

  static const char* value(const ::iiwa_msgs::CartesianPlane_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CartesianPlane_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::iiwa_msgs::CartesianPlane_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::iiwa_msgs::CartesianPlane_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // IIWA_MSGS_MESSAGE_CARTESIANPLANE_H
