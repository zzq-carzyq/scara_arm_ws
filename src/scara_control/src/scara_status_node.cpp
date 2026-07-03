#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
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
        joint_state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>(
            "/joint_states",
            10
        );

        timer_ = this->create_wall_timer(
            1s,
            std::bind(&ScaraStatusNode::publish_joint_state, this)
        );
    }
 
private:
    void print_status()
    {
        RCLCPP_INFO(this->get_logger(), "SCARA control node is alive.");
    }

    double joint1_position_ = 0.0;

    void publish_joint_state()
    {
        sensor_msgs::msg::JointState msg;
        msg.header.stamp = this->now();
        msg.name = {"joint1", "joint2", "joint_z", "joint_tool"};
        joint1_position_ += 0.1;
        msg.position = {joint1_position_, 0.0, 0.0, 0.0};

        joint_state_publisher_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Publish SCARA joint state.");
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_publisher_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ScaraStatusNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
