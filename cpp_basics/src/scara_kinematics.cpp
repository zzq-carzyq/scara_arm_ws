// 引入自己的头文件。
// 作用：确保这里实现的函数，和 .h 里声明的函数保持一致。
#include "scara_kinematics.h"

// 引入 C++ 数学库。
// 作用：使用 std::cos 和 std::sin。
#include <cmath>

// 实现角度转弧度。
// C++ 的 sin/cos 使用弧度，因此输入角度要先转换。
double deg_to_rad(double degrees) {
    const double pi = 3.141592653589793;
    return degrees * pi / 180.0;
}

// 实现 2R 平面机械臂正运动学。
// 公式：
// x = l1*cos(theta1) + l2*cos(theta1 + theta2)
// y = l1*sin(theta1) + l2*sin(theta1 + theta2)
Eigen::Vector2d compute_2r_forward_kinematics(
    double l1,
    double l2,
    double theta1_deg,
    double theta2_deg
) {
    // 将角度转换为弧度
    const double theta1_rad = deg_to_rad(theta1_deg);
    const double theta2_rad = deg_to_rad(theta2_deg);

    // 计算末端位置
    const double x =
        l1 * std::cos(theta1_rad) +
        l2 * std::cos(theta1_rad + theta2_rad);

    const double y =
        l1 * std::sin(theta1_rad) +
        l2 * std::sin(theta1_rad + theta2_rad);
    
    // 用 Eigen::Vector2d 同时返回 x 和 y。
    return Eigen::Vector2d(x, y);
}
