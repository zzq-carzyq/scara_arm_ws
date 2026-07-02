#include <iostream>
class GeneralDevice {
public:
    void device_type() {
        std::cout << "I am a device." << std::endl;
    }
};

class Robot_joint : public GeneralDevice {
public:
    void robot_joint_type() {
        std::cout << "I am a robot joint." << std::endl;
    }
};

int main() {
    Robot_joint joint1;
    joint1.device_type();
    joint1. robot_joint_type();

    return 0;
}
