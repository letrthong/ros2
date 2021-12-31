--------------------CODE-----------------------------------------
~/ros2_galactic$ 
	~/ros2_galactic$ cd src/
	~/ros2_galactic/src$ git clone https://github.com/letrthong/ros2 thong_ros2
	~/ros2_galactic/src$ cd ..
	~/ros2_galactic$ colcon list | grep "thong"

---------------------BUILD---------------------------------------
~/ros2_galactic$ 

	colcon build   --symlink-install --packages-select   thong_ipc
	colcon build   --symlink-install --packages-select  --allow-overriding   thong_ipc


	#colcon clean --packages-select   thong_ipc

---------------------TEST---------------------------------------
	. ~/ros2_galactic/install/local_setup.bash
	ros2 run  thong_ipc publisher.out