# 要求 CMake 的最低版本。
# 作用：避免你的 CMake 太旧，识别不了下面这些写法。
cmake_minimum_required(VERSION 3.16)

# 定义这个小 C++ 工程的名字。
# 这个名字不是最终可执行程序名，只是工程名。
project(scara_cpp_basics)

# 要求使用 C++17 标准。
# ROS2 和现代机器人 C++ 工程里经常会明确写 C++ 标准。
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Eigen3 库。
# Eigen 后面用来表示向量、矩阵、坐标、旋转、齐次变换。
find_package(Eigen3 REQUIRED)

# 定义一个可执行程序，名字叫 forward_kinematics。
# 它由两个 .cpp 文件编译链接而成：
# 1. src/main.cpp：程序入口
# 2. src/scara_kinematics.cpp：运动学公式实现
add_executable(forward_kinematics 
    src/main.cpp
    src/scara_kinematics.cpp
)

# 告诉编译器：头文件去 include/ 目录里找。
# 这样 main.cpp 里才能写 #include "scara_kinematics.h"。
target_include_directories(forward_kinematics 
    PRIVATE
    include 
)

# 把 Eigen3 挂到 forward_kinematics 这个程序上。
# 这样代码里才能使用 Eigen::Vector2d 等类型。
target_link_libraries(forward_kinematics 
    PRIVATE
    Eigen3::Eigen
)