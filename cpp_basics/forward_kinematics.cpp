#include <cmath>
#include <iostream>

int main(){
    const double pi = 3.141592653589793;
    const double l1 = 0.30;
    const double l2 = 0.20;
    const double theta1_deg = 0.0;
    const double theta2_deg = 0.0;
    const double theta1_rad = theta1_deg * pi / 180.0;
    const double theta2_rad = theta2_deg * pi / 180.0;
    const double x = l1 * cos(theta1_rad) + l2 * cos(theta1_rad + theta2_rad);
    const double y = l1 * sin(theta1_rad) + l2 * sin(theta1_rad + theta2_rad);
    std::cout << "theta1 = " << theta1_deg << " deg\n";
    std::cout << "theta2 = " << theta2_deg << " deg\n";
    std::cout << "x = " << x << " m\n";
    std::cout << "y = " << y << " m\n";
    return 0;
}