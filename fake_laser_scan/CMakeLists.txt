cmake_minimum_required(VERSION 2.8.3)
project(fake_laser_scan)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
  tf
)



###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES fake_laser_scan
#  CATKIN_DEPENDS roscpp sensor_msgs std_msgs tf
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
#include_directories(include)
include_directories(${catkin_INCLUDE_DIRS}
  include
)


## Declare a C++ executable
#add_executable(fake_laser_scan_node src/main.cpp)
add_executable(fake_laser_scan_node src/main.cpp src/fake_scan_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
#Sadd_dependencies(fake_laser_scan_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(fake_laser_scan_node
   ${catkin_LIBRARIES}

 )
