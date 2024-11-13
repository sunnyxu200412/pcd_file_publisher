#ifndef PCD_FILE_PUBLISHER_HPP
#define PCD_FILE_PUBLISHER_HPP

#include <memory>
#include <chrono>
#include <cstdlib>
#include <string>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
// #include <pcl_ros/pcl_ros/point_cloud.hpp>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

class PointCloudPublisher : public rclcpp::Node {
public:
    // Constructor
    PointCloudPublisher();

private:
    // Method to publish point cloud
    void publish_point_cloud();

    // Publisher and Timer members
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr demo_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif // PCD_FILE_PUBLISHER_HPP
