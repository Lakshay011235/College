/*
Write a program to demonstrate the use of friend function with Inline assignment
*/
#include <iostream>

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Inline declaration of friend function
    friend void setRadius(Circle &c, double r) {
        c.radius = r;
    }

    double getRadius() const {
        return radius;
    }
};

int main() {
    Circle c(1.0);
    std::cout << "Radius: " << c.getRadius() << std::endl;

    setRadius(c, 2.0);
    std::cout << "Radius: " << c.getRadius() << std::endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
