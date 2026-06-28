# C++ Basics: 2R Forward Kinematics

    这个目录用于练习 C++ 多文件工程、CMake 构建、Eigen 向量类型，以及 2R 平面机械臂正运动学。

    ## 文件结构

        ```text
        cpp_basics/
        ├── CMakeLists.txt
        ├── include/
        │   └── scara_kinematics.h
        └── src/
            ├── main.cpp
            └── scara_kinematics.cpp

        - include/scara_kinematics.h：声明运动学函数接口。
        - src/scara_kinematics.cpp：实现角度转换和 2R 正运动学公式。
        - src/main.cpp：读取命令行参数，调用运动学函数，打印末端位置。
        - CMakeLists.txt：定义如何编译这个 C++ 小工程。

    ## Build

        在 cpp_basics 目录下运行：

        cmake -S . -B build
        cmake --build build

        ## Run

        程序需要 4 个输入参数：

        l1 l2 theta1_deg theta2_deg

        运行示例：

        ./build/forward_kinematics 0.3 0.2 30 45

        示例输出：

        x = 0.311571 m
        y = 0.343185 m

        边界测试：

        ./build/forward_kinematics 0.3 0.2 0 0

        预期输出：

        x = 0.5 m
        y = 0 m

        ## Error Handling

        如果参数数量不对：

        ./build/forward_kinematics 0.3 0.2 30

        程序会提示：

        Usage: ./build/forward_kinematics l1 l2 theta1_deg theta2_deg

        如果参数不是合法数字：

        ./build/forward_kinematics 0.3 abc 30 45

        程序会提示：

        Error: all input parameters must be valid numbers.
        Usage: ./build/forward_kinematics l1 l2 theta1_deg theta2_deg

    ## Current Limitations

        - 目前只计算 2R 平面机械臂的末端位置 (x, y)。
        - 目前没有检查连杆长度是否为正数。
        - 目前没有处理角度范围限制。
        - 后续会扩展到 SCARA 机械臂项目中的更完整运动学和控制链路。