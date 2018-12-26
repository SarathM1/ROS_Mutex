#include "boost/interprocess/sync/named_mutex.hpp"
#include "ros/ros.h"

using namespace boost::interprocess;

int main(int argc, char **argv) {
    // This type of initialisation requires C++11
    named_mutex named_mtx3{open_or_create, "mtx3"};
    ROS_INFO("Node3 Waiting for lock to release");
    named_mtx3.lock();
    ROS_INFO("Node3 running. .");
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);
    for(int i=5;i>0;i--)
    {
        ROS_INFO("Node3 %d", i);
        loop_rate.sleep();
    }
    named_mtx3.unlock();
    named_mutex::remove("mtx3");
    return 0;
}
