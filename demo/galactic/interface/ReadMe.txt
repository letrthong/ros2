https://docs.ros.org/en/foxy/Tutorials/Custom-ROS2-Interfaces.html

https://github.com/ros2/example_interfaces


cmake

find_package(rclcpp RQEUIRED)
find_package(std_msgs RQEUIRED)
find_package(std_srvs RQEUIRED)
--------------------CODE-----------------------------------------
	~/ros2_galactic$ 
	~/ros2_galactic$ cd src/
	~/ros2_galactic/src$ git clone https://github.com/letrthong/ros2 thong_ros2
	~/ros2_galactic/src$ cd ..
	~/ros2_galactic$ colcon list | grep "thong"

---------------------BUILD---------------------------------------
   ~/ros2_galactic$ 
	colcon build   --symlink-install --packages-select   thong_interfaces
	colcon build   --symlink-install --packages-select  --allow-overriding   thong_interfaces

	#colcon clean build --packages-select   thong_interfaces

---------------------TEST---------------------------------------
	. ~/ros2_galactic/install/local_setup.bash
	. install/setup.bash
	ros2 interface show thong_interfaces/msg/MyNum
----------------------RESULT----------------------------------
thonglt@thonglt-virtual-machine:~/ros2_galactic$ . install/setup.bash
thonglt@thonglt-virtual-machine:~/ros2_galactic$ ros2 interface list | grep "thong"
    thong_interfaces/msg/MyNum
    thong_interfaces/srv/AddThreeInts
