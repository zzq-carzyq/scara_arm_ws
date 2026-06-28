#pragma once

// Eigen/Dense 提供 Eigen::Vector2d 等向量、矩阵类型。
// 这里用 Vector2d 表示二维位置 (x, y)。
#include <Eigen/Dense>

// 把角度转换成弧度。
// 原因：C++ 标准库里的 sin/cos 接收的是弧度，不是角度。
// 输入：degrees，例如 30.0
// 输出：对应的弧度值
double deg_to_rad(double degrees);

// 计算 2R 平面机械臂的正运动学。
// 输入：
// - l1, l2：两段连杆长度，单位 m
// - theta1_deg, theta2_deg：两个关节角，单位 degree
// 输出：
// - Eigen::Vector2d(x, y)，表示末端在平面内的位置
Eigen::Vector2d compute_2r_forward_kinematics(
    double l1,
    double l2,
    double theta1_deg,
    double theta2_deg
);

