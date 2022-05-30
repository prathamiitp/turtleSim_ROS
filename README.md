<div align="center">

# Turtle Sim
## Virtual bot movement control 

<img src="https://img.shields.io/badge/ros-%230A0FF9.svg?style=for-the-badge&logo=ros&logoColor=white"/>
</div>

#
## Features
1) Makes a polygon with user specified edge count and user specified side length by TurtleSim in ROS Noetic on Ubuntu 20.04.

#
## Installation

> Running in Local Mechine 
> 

#### [ Pre-requisite ] : 
- Run this command to get the required pre-requisite.
``` 
sudo apt-get install libavcodec-dev libsdl1.2-dev xsltproc libbullet-dev libsdl1.2-dev libgoogle-glog-dev protobuf-compiler python-wstool
```

##### Some reffernences :
- [Ros Tutorials](http://wiki.ros.org/ROS/Tutorials)
- [Ros Installation](http://wiki.ros.org/noetic/Installation/Ubuntu)

#### [ step 1 (Setting up ROS)] :
- Setup your pc to accept software from packages.ros.org
``` 
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
```  

   
- Setup key and installation
``` 
sudo apt install curl
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo apt update
sudo apt install ros-noetic-desktop-full
```  
  
  
- Envirnment setup for ROS
(only the ROS version that you currently want to use must be in the .bashrc file if you have multiple versions installed)
``` 
source /opt/ros/noetic/setup.bash
```
add this line to your .bashrc file to make it globally available or run the command below
```
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
```  
  
  
- Dependencies for building packages and setting up Rosdep
``` 
sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
sudo apt install python3-rosdep
sudo rosdep init
rosdep update
```  
to cross checking check for these 2 names in the output (Ros_package_path, Ros_root) of the following command
``` 
printenv | grep ROS
```  
  
  
#### [ step 2 (Creating catkin workspace)] :
- Create a ROS workspace
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
```  
  
   
- Envirnment setup for catkin workspace
remember (only the catkin workspace you are curruntly using has to be sourecd and put into .bashrc)
``` 
source ~/catkin_ws/devel/setup.bash
```
add this line to your .bashrc file to make it globally available or run the command below
```
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
```
now cd to your home directory and proceed further    
    
     
- Installing a ROS Tutorial package
```
sudo apt-get install ros-noetic-ros-tutorials
```  
  
  
- Creating a Catkin package and building catkin workspace
```
cd ~/catkin_ws/src
catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
cd ~/catkin_ws
catkin_make
```  
to check your dependencies use rospack 
```
depends1 beginner_tutorials
```
cd to your home directory and proceed furthur  
   
   
- Building packages
```
source /opt/ros/kinetic/setup.bash
cd ~/catkin_ws
catkin_make
catkin_make install
```
now the installation is complete, you can close all terminal.
  
  
#### [ step 3 (Testing your setup and turtle!!!)] :
```
cd ~/catkin_ws
catkin_make
roscore
```
in new terminal
```
rosrun turtlesim turtlesim_node
```
in another new terminal
```
rosrun turtlesim turtle_teleop_key
```  
now you can run your turtle with your arrow keys by clicking on the turtsim window.

  
#### [ step 4 (Running my project)] :
- copy the polynomial file in catkin_wa/src and run the following command
```
cd ~/catkin_ws
catkin_make
roscore
```
in new terminal
```
rosrun turtlesim turtlesim_node
```
in another new terminal
```
rosrun polynomial Pmain
```
and you should be able to run your turtle based on simple numeric input from your terminal. 
  
    
      
<div align="center">

# !!!Happy tinkering!!!
Don't forget to watch the video of the project [here](https://github.com/prathamiitp/turtleSim_ROS/blob/master/polygon.mp4)
</div>
