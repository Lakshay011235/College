/*
Write a program to define the function template for swapping two items of various datatypes such as integers, float and characters
*/
#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Before swap: \tx = " << x << "\ty = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: \tx = " << x << "\ty = " << y << std::endl;

    char c1 = 'A', c2 = 'B';
    std::cout << "Before swap: \tc1 = " << c1 << "\tc2 = " << c2 << std::endl;
    swap(c1, c2);
    std::cout << "After swap: \tc1 = " << c1 << "\tc2 = " << c2 << std::endl;

    float f1 = 1.23, f2 = 4.56;
    std::cout << "Before swap: \tf1 = " << f1 << "\tf2 = " << f2 << std::endl;
    swap(f1, f2);
    std::cout << "After swap: \tf1 = " << f1 << "\tf2 = " << f2 << std::endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
