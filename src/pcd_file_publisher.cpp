#include <memory>
#include <chrono>
#include <cstdlib>
#include <string>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <rclcpp/rclcpp.hpp>
#include <pcd_file_publisher.hpp>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>



using namespace std::chrono_literals;


PointCloudPublisher::PointCloudPublisher()
    : Node("point_cloud_publisher") {
        // Create a publisher for the PointCloud2 type
        demo_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("cloud_topic", 10);
        
        // Timer to publish at 1 Hzs
        timer_ = this->create_wall_timer(
            10s, std::bind(&PointCloudPublisher::publish_point_cloud, this));
        
        RCLCPP_INFO(this->get_logger(), "Publishing point cloud on topic 'cloud_topic' once every second.");
}

    void PointCloudPublisher::publish_point_cloud() {
        // Create point cloud object
        auto my_cloud = std::make_shared<sensor_msgs::msg::PointCloud2>();

        pcl::PointCloud<pcl::PointXYZRGB> cloud_;
        
        int height = 200;
        int width = 200;
        // TODO(lucasw) generate a cube or sphere instead, more interesting than 2d

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                const float fr = static_cast<float>(i*j+j) / static_cast<float>(height*width);
                pcl::PointXYZRGB pt;
                pt = pcl::PointXYZRGB();
                pt.x = static_cast<float>(j);
                pt.y = static_cast<float>(i);
                if((j > 30 && j < 40) || (j > 70 && j < 80))
                    pt.z = 3.0;
                else 
                    pt.z = 0.0;
                cloud_.points.push_back(pt);
            }
        }

        pcl::toROSMsg(cloud_, *my_cloud);
        my_cloud->header.frame_id = "map";
        std::cout << "here" << std::endl;
        
        pcl::PointCloud<pcl::PointXYZRGB> out_pointcloud;
        pcl::fromROSMsg(*my_cloud, out_pointcloud);

        for(int i = 0 ; i < out_pointcloud.points.size(); ++i){
            std::cout << "x: " << out_pointcloud.points[i].x << " y: "  <<out_pointcloud.points[i].y << " z: "<<out_pointcloud.points[i].z << std::endl;
        }

        // Publish point cloud
        demo_publisher_->publish(*my_cloud);
    }


//#endif


int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PointCloudPublisher>());
    rclcpp::shutdown();
    return 0;
}


