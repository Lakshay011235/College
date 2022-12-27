/*
Using  the  concept  of  function  overloading,  write  function  for  calculating  area  of  triangle,  circle  and rectangle
*/
#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the area of a triangle
float area(float side1, float side2, float side3) {
    float s = (side1+side2+side3)/2;
    return sqrtf(s*(s-side1)*(s-side2)*(s-side3));
}

// Function to calculate the area of a circle
float area(float radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a rectangle
float area(float length, float width) {
    return length * width;
}

int main() {
    // Calculate the area of a triangle
    cout << "Area of triangle: " << area(5, 12, 13) << endl;

    // Calculate the area of a circle
    cout << "Area of circle: " << area(10) << endl;

    // Calculate the area of a rectangle
    cout << "Area of rectangle: " << area(5, 10) << endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
