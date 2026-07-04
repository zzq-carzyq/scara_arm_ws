import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    # 找到 scara_description 包安装后的 share 目录
    scara_description_share = get_package_share_directory("scara_description")

    # 拼出 URDF 文件的完整路径
    urdf_path = os.path.join(
        scara_description_share,
        "urdf",
        "scara.urdf",
    )

    # 读取 URDF 文件内容，作为 robot_description 参数传给robot_state_publisher
    with open(urdf_path, "r") as urdf_file:
        robot_description = urdf_file.read()

    return LaunchDescription([
        # 你的 C++ 节点：负责发布 /joint_states
        Node(
            package="scara_control",
            executable="scara_status_node",
            name="scara_status_node",
            output="screen",
        ),

        # ROS2 标准节点：负责把 URDF + /joint_states 转换成 TF
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="screen",
            parameters=[{
                "robot_description": robot_description,
            }],
        ),
    ])
