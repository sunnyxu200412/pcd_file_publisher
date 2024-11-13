# cmake_minimum_required(VERSION 3.8)
# cmake_policy(SET CMP0074 NEW)
# project(pcd_file_publisher)

# # Compiler warnings for stricter checks
# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # Find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(pcl_ros REQUIRED)
# find_package(pcl_conversions REQUIRED)
# find_package(PCL REQUIRED COMPONENTS common io)  # Make sure these components are included
# find_package(Eigen3 REQUIRED)

# # Your existing C++ standard setting
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)



# # Debug messages
# message(STATUS "PCL_INCLUDE_DIRS: ${PCL_INCLUDE_DIRS}")
# message(STATUS "Eigen3_INCLUDE_DIRS: ${Eigen3_INCLUDE_DIRS}")


# # Include directories
# include_directories(
#   include
#   ${PCL_INCLUDE_DIRS}
#   ${Eigen3_INCLUDE_DIRS}
# )

# add_definitions(${PCL_DEFINITIONS})

# # Define executable
# add_executable(pcd_file_publisher
#   src/main.cpp
#   src/pcd_file_publisher.cpp
# )

# # Link libraries
# target_link_libraries(pcd_file_publisher
#   rclcpp::rclcpp
#   pcl_ros::pcl_ros
#   pcl_conversions::pcl_conversions
#   ${PCL_LIBRARIES}  # Links all specified PCL libraries
#   Eigen3::Eigen
# )

# # Specify ament dependencies
# ament_target_dependencies(
#   pcd_file_publisher
#   rclcpp
#   pcl_ros
#   pcl_conversions
# )

# # Install the executable
# install(
#   TARGETS pcd_file_publisher
#   DESTINATION lib/${PROJECT_NAME}
# )

# # Testing (optional)
# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   set(ament_cmake_copyright_FOUND TRUE)
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

# ament_package()
cmake_minimum_required(VERSION 3.5)
project(pcd_file_publisher)
include_directories(
  include
  ${PCL_INCLUDE_DIRS}
  /opt/ros/humble/include
)

cmake_policy(SET CMP0074 NEW)  # Use PCL_ROOT if specified
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE BOOL "Suppress developer warnings")

# Find required packages
find_package(ament_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL REQUIRED)  # Add this line

# Create the executable
add_executable(pcd_file_publisher src/pcd_file_publisher.cpp)

# Link the libraries
ament_target_dependencies(pcd_file_publisher rclcpp pcl_ros pcl_conversions PCL)

# Install the target
install(TARGETS
  pcd_file_publisher
  DESTINATION lib/${PROJECT_NAME}
)

# Finalize the package
ament_package()
