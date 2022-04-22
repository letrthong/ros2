cmake_minimum_required(VERSION 3.5)

project(in_c)

#################################################
# compiler settings
#################################################

# Default to C11
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 11)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(ament_cmake_ros REQUIRED)
find_package(rcl REQUIRED)
find_package(rcl_lifecycle REQUIRED)
find_package(rclc REQUIRED)
find_package(rclc_lifecycle REQUIRED)
find_package(std_msgs REQUIRED)
find_package(lifecycle_msgs REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(rclc_parameter REQUIRED)
find_package(Threads REQUIRED)

include_directories(include)
 
add_executable(example_action_client src/example_action_client.c)
ament_target_dependencies(example_action_client rcl rcl_action rclc example_interfaces)

install(TARGETS
  example_action_client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

