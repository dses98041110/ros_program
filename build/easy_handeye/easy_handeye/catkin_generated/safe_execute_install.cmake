execute_process(COMMAND "/home/yu/catkin_ws/build/easy_handeye/easy_handeye/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/yu/catkin_ws/build/easy_handeye/easy_handeye/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
