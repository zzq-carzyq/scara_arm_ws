// 引入自己写的头文件。
// 作用：让 main.cpp 知道有 deg_to_rad 和 compute_2r_forward_kinematics 这两个函数。
#include "scara_kinematics.h"

// 引入 C++ 输入输出库。
// 作用：后面用 std::cout 把计算结果打印到终端。
#include <iostream>

// 引入 C++ 字符串库。
// 作用：后面用 std::stod 把命令行文本转换为 double 类型。
#include <string>

// C++ 程序的入口函数。
// 程序运行时，会从 main() 里面的第一行开始执行。
int main(int argc, char* argv[]) {
    // 程序需要 4 个输入参数：l1, l2, theta1_deg, theta2_deg。
    // 加上程序名本身，argc 应该等于 5。
    if (argc != 5) {
        // 如果参数数量不对，就打印提示信息，并返回错误码 1。
        std::cout << "Usage: ./build/forward_kinematics l1 l2 theta1_deg theta2_deg\n";
        return 1;
    }

    // 第一段连杆长度，单位是m。
    // argv[1] 是命令行输入的第1个参数，类型是 char*，需要用 std::stod 转换为 double。
    const double l1 = std::stod(argv[1]);

    // 第二段连杆长度，单位是m。
    // argv[2] 是命令行输入的第2个参数，类型是 char*，需要用 std::stod 转换为 double。
    const double l2 = std::stod(argv[2]);

    // 第一个关节的角度，单位是度。
    // argv[3] 是命令行输入的第3个参数，类型是 char*，需要用 std::stod 转换为 double。
    const double theta1_deg = std::stod(argv[3]);

    // 第二个关节的角度，单位是度。
    // argv[4] 是命令行输入的第4个参数，类型是 char*，需要用 std::stod 转换为 double。
    const double theta2_deg = std::stod(argv[4]);

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