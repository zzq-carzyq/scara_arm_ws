#include "rclcpp/rclcpp.hpp"

#include <chrono>
#include <functional>
#include <memory>

using namespace std::chrono_literals;

class ScaraStatusNode : public rclcpp::Node
{
public:
    ScaraStatusNode()
    : Node("scara_status_node")
    {
        timer_ = this->create_wall_timer(
            1s,
            std::bind(&ScaraStatusNode::print_status, this));
    }

private:
    void print_status()
    {
        RCLCPP_INFO(this->get_logger(), "SCARA control node is alive.");
    }

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ScaraStatusNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
