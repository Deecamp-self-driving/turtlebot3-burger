//
// Created by lzw on 19-1-26.
//

#include "ros/ros.h"
#include "car_detect/DetectCarArea.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "car_detect_client");
    if (argc != 4)
    {
        ROS_INFO("usage: add_two_ints_client X Y length");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<car_detect::DetectCarArea>("detect_car_area");
    car_detect::DetectCarArea srv;
    srv.request.x = atoll(argv[1]);
    srv.request.y = atoll(argv[2]);
    srv.request.length = atoll(argv[3]);
    if (client.call(srv))
    {
        ROS_INFO("Result: %d", (int)srv.response.result);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    return 0;
}