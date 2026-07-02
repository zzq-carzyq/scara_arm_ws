#include <iostream>

class Counter {
private:
    int value = 0;

public:
    void add_two() {
        value += 2;
    }
    int get_value() {
        return value;
    }


};

int main() {
    Counter c;
    c.add_two();
    c.add_two();
    std::cout << "counter value = " << c.get_value() << std::endl;
}