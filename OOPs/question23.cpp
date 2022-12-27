/*
Write a program to find the sum of two numbers declared in a class and display the numbers and sum using friend class.
*/
#include <iostream>

using namespace std;

// Class with private member variables a and b
class Numbers {
private:
    int a, b;

public:
    Numbers(int x, int y) {
        a = x;
        b = y;
    }

    // Declare Display class as a friend
    friend class Display;
};

// Friend class with a function to display the numbers and their sum
class Display {
public:
    void show(Numbers n) {
        cout << "Numbers: " << n.a << " " << n.b << endl;
        cout << "Sum: " << n.a + n.b << endl;
    }
};

int main() {
    // Create a Numbers object with values 10 and 20
    Numbers numbers(10, 20);

    // Create a Display object and use it to show the numbers and their sum
    Display display;
    display.show(numbers);

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
