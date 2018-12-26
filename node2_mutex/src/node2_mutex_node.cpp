#include <fstream>
#include <iostream>
#include <string>

#include "boost/interprocess/sync/named_mutex.hpp"
#include "boost/interprocess/sync/scoped_lock.hpp"
#include "boost/thread/thread.hpp"

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
using namespace boost::interprocess;

int main(int argc, char **argv) {
    // This type of initialisation requires C++11
    named_mutex named_mtx2{open_or_create, "mtx2"};
    ROS_INFO("Node2 Waiting for lock to release");
    named_mtx2.lock();
    ROS_INFO("Node2 running. .");
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(1);
    for(int i=5;i>0;i--)
    {
        ROS_INFO("%d", i);
        loop_rate.sleep();
    }
    named_mtx2.unlock();
    return 0;
}
