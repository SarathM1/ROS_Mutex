# ROS_Mutex
Method to use **Boost _named-mutex_** to launch nodes in a specific order.

## Dependencies
- Boost
```sh
sudo apt install libboost1.58-all-dev
```
  - Edit CMakeLists.txt and add Boost. Refer the given CMakeLists.txt
- C++ 11
  - Edit CMakeLists.txt and add following line
```cmake
add_compile_options(-std=c++11)
```

## Setup
- Create a catkin workspace
```sh
mkdir ~/catkin_ws
cd ~/catkin_ws
```
- Clone this repository
```sh
git clone https://github.com/SarathM1/ROS_Mutex.git ~/catkin_ws/src
```
- Build using catkin_make
```sh
catkin_make
```

## Running the code
### Using ROS launchfile
```sh
roslaunch mutex_init launchFile.launch
```
### Using Tmuxinator
> Install tmuxinator using `sudo apt install tmuxinator`
- Edit `~/catkin_ws/src/.tmuxinator.yml` file
- Start tmux session using commands below
```sh
cd ~/catkin_ws/src
mux .
```

## Notes
- mutex_init_node of mutex_init package must run before all nodes
- After that run each node in the order of filename node1_mutex_node, node2_mutex_node and so on
