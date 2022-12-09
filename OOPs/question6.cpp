/*
Write a C++ program to define function power to raise a number m to a power n the function takes a double value for m. And integer value for n and return the result correctly use a default value of 2 for n to make the function calculate squares when this argument is omitted.
*/
#include <iostream>
#include <cmath>

// Function to raise m to the power of n
double power(double m, int n = 2) {
    return std::pow(m, n);
}

int main() {
    std::cout << "power(3.0) = " << power(3.0) << '\n';  // power(3.0) = 9
    std::cout << "power(3.0, 4) = " << power(3.0, 4) << '\n';  // power(3.0, 4) = 81
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
