// 引入自己写的头文件。
// 作用：让 main.cpp 知道有 deg_to_rad 和 compute_2r_forward_kinematics 这两个函数。
#include "scara_kinematics.h"

// 引入 C++ 输入输出库。
// 作用：后面用 std::cout 把计算结果打印到终端。
#include <iostream>

// C++ 程序的入口函数。
// 程序运行时，会从 main() 里面的第一行开始执行。
int main() {
    // 第一段连杆长度，单位是m。
    const double l1 = 0.30;

    // 第二段连杆长度，单位是m。
    const double l2 = 0.20;

    // 第一个关节的角度，单位是度。
    const double theta1_deg = 30.0;

    // 第二个关节的角度，单位是度。
    const double theta2_deg = 45.0;
    
    // 调用2R正运动学函数，计算末端执行器的坐标。
    const Eigen::Vector2d position = compute_2r_forward_kinematics(
        l1,
        l2,
        theta1_deg,
        theta2_deg
    );

    // 打印计算结果。
    std::cout << "x = " << position.x() << " m\n";
    std::cout << "y = " << position.y() << " m\n";

    // return 0 表示程序正常结束。
    return 0;
}