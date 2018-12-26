# ROS_Mutex
Method to use Boost named_mutex to launch nodes in a specific order.

## Dependencies
- Boost
- C++ 11

## Setup
- Create a catkin workspace
  - mkdir ~/catkin_ws
  - cd ~/catkin_ws
- Clone this repository
  - git clone https://github.com/SarathM1/ROS_Mutex.git ~/catkin_ws/src
- Build using catkin_make
  - catkin_make
  
## Running the code
  roslaunch mutex_init launchFile.launch
  
## Notes
- mutex_init_node of mutex_init package must run before all nodes
- After that run each node in the order of filename node1_mutex_node, node2_mutex_node and so on
