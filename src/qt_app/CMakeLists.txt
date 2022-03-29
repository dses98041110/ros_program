cmake_minimum_required(VERSION 3.0.2)
project(qt_app)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)
find_package(Qt5  REQUIRED COMPONENTS  Widgets  )
find_package(Qt5Core REQUIRED)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_add_resources(QT_RESOURCES_CPP qt_resources/piece/piece.qrc)

set(SOURCES
	src/mainwindow.cpp
	src/Bishop.cpp      
	src/ChessPiece.cpp  
	src/Knight.cpp     
	src/Pawn.cpp
	src/Rook.cpp
	src/ChessBoard.cpp 
	src/Game.cpp      
	src/main.cpp    
	src/Piece.cpp
	src/ChessBox.cpp   
	src/King.cpp     
	src/mainwindow.cpp
	src/Queen.cpp
	src/RobotThread.cpp
)

set(FORMS
  src/mainwindow.ui
)



catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES qt_app
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
	include/qt_app
	${catkin_INCLUDE_DIRS}
)




#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_qt_app.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
add_executable(${PROJECT_NAME}_node ${SOURCES} ${FORMS} ${QT_RESOURCES_CPP})

target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}_node Qt5::Widgets)

