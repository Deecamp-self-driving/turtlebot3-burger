//
// Created by lzw on 19-1-26.
//

#include "ros/ros.h"
#include "car_detect/DetectCarArea.h"

bool detect(car_detect::DetectCarArea::Request  &req,
            car_detect::DetectCarArea::Response &res)
{
    ROS_INFO("request: x=%ld, y=%ld, length=%ld", (long int)req.x, (long int)req.y, (long int)req.length);

    // get the scan result in the area.


    // judge whether there is a car.

    res.result = true;
    ROS_INFO("sending back response: [%d]", res.result);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "car_detect");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("detect_car_area", detect);
    ROS_INFO("Ready to detect car.");
    ros::spin();

    return 0;
}