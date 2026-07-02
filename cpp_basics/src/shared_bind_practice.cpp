#include <iostream>
#include <functional>
#include <memory>

namespace control{
    class ScaraStatus {
        private:
            int joint_count_;
        
        public:
            void set_joint_count() {
                this->joint_count_ = 4;
            }
            void print_status() {
                std::cout << "SCARA joint count: " << this->joint_count_ << std::endl;
            }
            void start_once() {
                auto task = std::bind(&ScaraStatus::print_status, this);
                task();
            }
    };
}

int main() {
    auto node = std::make_shared<control::ScaraStatus>();
    node->set_joint_count();
    node->start_once();
}

