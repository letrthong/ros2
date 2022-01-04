# Build
colcon build   --symlink-install --packages-select  --allow-overriding   node_ipc_client

# Run
. ~/ros2_galactic/install/local_setup.bash
ros2 run  thong_ipc_action node_client