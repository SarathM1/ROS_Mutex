#include "boost/interprocess/sync/named_mutex.hpp"
#include "ros/ros.h"
using namespace boost::interprocess;

int main(int argc, char **argv) {
    // This type of initialisation requires C++11
    named_mutex named_mtx1{open_or_create, "mtx1"};
    named_mutex named_mtx2{open_or_create, "mtx2"};
    ROS_INFO("Node1 Waiting for lock to release");
    named_mtx1.lock();
    ROS_INFO("Node1 running. .");
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);
    for(int i=5;i>0;i--)
    {
        ROS_INFO("Node1 %d", i);
        loop_rate.sleep();
    }
    named_mtx1.unlock();
    named_mutex::remove("mtx1");
    named_mtx2.unlock();
    return 0;
}
