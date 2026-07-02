#include <iostream>
#include <string>

class GeneralDevice {
private:
    std::string name;

public:
    GeneralDevice(std::string device_name) : name(device_name){
    }

    void print_name() {
        std::cout << "My name is: " << name << std::endl;
    }

};

class RobotJoint : public GeneralDevice {
public:
    RobotJoint() : GeneralDevice("ROBOT_JOINT_1") {
    }

    void move() {
        std::cout << "I'm moving." << std::endl;
    }
};

int main() {
    RobotJoint joint1;
    joint1.print_name();
    joint1.move();

    return 0;
}
