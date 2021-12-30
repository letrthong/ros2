thonglt@thonglt-virtual-machine:~/ros2_galactic$ 
thonglt@thonglt-virtual-machine:~/ros2_galactic$ cd src/
thonglt@thonglt-virtual-machine:~/ros2_galactic/src$ git clone https://github.com/letrthong/ros2 thong_ros2

thonglt@thonglt-virtual-machine:~/ros2_galactic/src$ cd ..
thonglt@thonglt-virtual-machine:~/ros2_galactic$ colcon list | grep "thong"

colcon build   --packages-select  --allow-overriding   thong_ipc
 