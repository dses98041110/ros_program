// Generated by gencpp from file visp_tracker/KltPoints.msg
// DO NOT EDIT!


#ifndef VISP_TRACKER_MESSAGE_KLTPOINTS_H
#define VISP_TRACKER_MESSAGE_KLTPOINTS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <visp_tracker/KltPoint.h>

namespace visp_tracker
{
template <class ContainerAllocator>
struct KltPoints_
{
  typedef KltPoints_<ContainerAllocator> Type;

  KltPoints_()
    : header()
    , klt_points_positions()  {
    }
  KltPoints_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , klt_points_positions(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::visp_tracker::KltPoint_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::visp_tracker::KltPoint_<ContainerAllocator> >::other >  _klt_points_positions_type;
  _klt_points_positions_type klt_points_positions;





  typedef boost::shared_ptr< ::visp_tracker::KltPoints_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::visp_tracker::KltPoints_<ContainerAllocator> const> ConstPtr;

}; // struct KltPoints_

typedef ::visp_tracker::KltPoints_<std::allocator<void> > KltPoints;

typedef boost::shared_ptr< ::visp_tracker::KltPoints > KltPointsPtr;
typedef boost::shared_ptr< ::visp_tracker::KltPoints const> KltPointsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::visp_tracker::KltPoints_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::visp_tracker::KltPoints_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::visp_tracker::KltPoints_<ContainerAllocator1> & lhs, const ::visp_tracker::KltPoints_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.klt_points_positions == rhs.klt_points_positions;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::visp_tracker::KltPoints_<ContainerAllocator1> & lhs, const ::visp_tracker::KltPoints_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace visp_tracker

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::visp_tracker::KltPoints_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::visp_tracker::KltPoints_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visp_tracker::KltPoints_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visp_tracker::KltPoints_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visp_tracker::KltPoints_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visp_tracker::KltPoints_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::visp_tracker::KltPoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "681548d0f72044b7f086e3985d86f93c";
  }

  static const char* value(const ::visp_tracker::KltPoints_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x681548d0f72044b7ULL;
  static const uint64_t static_value2 = 0xf086e3985d86f93cULL;
};

template<class ContainerAllocator>
struct DataType< ::visp_tracker::KltPoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "visp_tracker/KltPoints";
  }

  static const char* value(const ::visp_tracker::KltPoints_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::visp_tracker::KltPoints_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Stamped list of KLT points positions.\n"
"#\n"
"# KLT points positions associated with a particular timestamp.\n"
"# Used by the viewer to display KLT points positions and allow\n"
"# tracking debug.\n"
"\n"
"Header header                        # Header (required for synchronization).\n"
"KltPoint[] klt_points_positions      # List of KLT points positions.\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: visp_tracker/KltPoint\n"
"# KLT point position.\n"
"\n"
"float64 i      # i position in the image\n"
"float64 j      # j position in the image\n"
"int32   id     # Point id\n"
;
  }

  static const char* value(const ::visp_tracker::KltPoints_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::visp_tracker::KltPoints_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.klt_points_positions);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct KltPoints_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::visp_tracker::KltPoints_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::visp_tracker::KltPoints_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "klt_points_positions[]" << std::endl;
    for (size_t i = 0; i < v.klt_points_positions.size(); ++i)
    {
      s << indent << "  klt_points_positions[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::visp_tracker::KltPoint_<ContainerAllocator> >::stream(s, indent + "    ", v.klt_points_positions[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // VISP_TRACKER_MESSAGE_KLTPOINTS_H