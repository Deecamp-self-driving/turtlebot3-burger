//
// Created by lzw on 19-1-26.
//

#include "ros/ros.h"
#include "car_detect/DetectCarArea.h"
#include <tf/transform_listener.h>

bool detect(car_detect::DetectCarArea::Request  &req,
            car_detect::DetectCarArea::Response &res)
{
    ROS_INFO("request: x=%ld, y=%ld, length=%ld", (long int)req.x, (long int)req.y, (long int)req.length);

    // get the scan result in the area.
    tf::TransformListener listener;
    tf::StampedTransform transform;
    try{
        listener.lookupTransform("/map", "/base_scan",
                                 ros::Time(0), transform);
    }
    catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
        ros::Duration(1.0).sleep();
    }

    // judge whether there is a car.

    res.result = true;
    ROS_INFO("sending back response: [%d]", res.result);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "car_detect");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("IsOK", detect);
    ROS_INFO("Ready to detect car.");
    ros::spin();

    return 0;
}