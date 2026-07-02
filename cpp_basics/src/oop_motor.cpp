#include <iostream>

class MotorStatus {
private: 
    int speed = 0;

public:
    void increase_speed() {
        speed += 100;
    }

    int get_speed() {
        return speed;
    }
};

int main() {
    MotorStatus m;
    m.increase_speed();
    m.increase_speed();
    m.increase_speed();
    std::cout << "motor_speed: " << m.get_speed() << std::endl;
}