#include "boost/interprocess/sync/named_mutex.hpp"
#include "ros/ros.h"
using namespace boost::interprocess;

int main(int argc, char **argv) {
    // This type of initialisation requires C++11
    named_mutex named_mtx1{open_or_create, "mtx1"};
    named_mutex named_mtx2{open_or_create, "mtx2"};
    ROS_INFO("Locking mtx1");
    named_mtx1.lock();
    ROS_INFO("Locking mtx2");
    named_mtx2.lock();
    ROS_INFO("\tUnlocking mtx1");
    named_mtx1.unlock();
    return 0;
}
