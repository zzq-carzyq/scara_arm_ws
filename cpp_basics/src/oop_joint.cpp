#include <iostream>

class JointStatus {
private:
    int theta;

public:
    JointStatus(int initial_theta) {
        theta = initial_theta;
    }

    void theta_increase() {
        theta += 15;
    }

    int get_theta() {
        return theta;
    }
};

int main() {
    JointStatus joint(30);
    joint.theta_increase();
    joint.theta_increase();
    std::cout << "joint_theta: " << joint.get_theta() << std::endl;

    return 0;
}