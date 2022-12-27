/*
Write a program to illustrate how Template function can be overloaded
*/
#include <iostream>

using namespace std;

// Function template to calculate the sum of two numbers
template <typename T>
T sum(T a, T b) {
    return a + b;
}

// Overloaded function template to calculate the sum of three numbers
template <typename T>
T sum(T a, T b, T c) {
    return a + b + c;
}

int main() {
    // Call sum with two arguments
    cout << "Sum of 1 and 2: " << sum(1, 2) << endl;

    // Call sum with three arguments
    cout << "Sum of 1, 2, and 3: " << sum(1, 2, 3) << endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
