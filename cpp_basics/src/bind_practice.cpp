#include <iostream>
#include <functional>

namespace control {
    class MotorStatus {
        private:
            int speed_;
        
        public:
            void set_speed(int speed)
            {
                this->speed_ = speed;
            }

            void print_status() 
            {
                std::cout << "motor speed: " << this->speed_ << std::endl;
            }

            void start_once() 
            {
                auto task = std::bind(&MotorStatus::print_status, this);
                task();
            }
    };
}

int main()
{
    control::MotorStatus motor;
    motor.set_speed(120);
    motor.start_once();

    return 0;


}

