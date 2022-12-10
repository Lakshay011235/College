/*
Consider a class point containing x and y coordinates. Write necessary functions for the following 
cases:
1. to accept a point
2. to display it
3. to find distance between two points using operator overloading (-)(Use friend function).

*/
#include <iostream>
#include <cmath>
class point{
    public:
        int x; int y;
        point(){
            x=0;    y=0;
        }
        // Function to input / accept a point 
        point input(int x_, int y_){
            x=x_;   y=y_;
            return *this;
        }
        // Function to output / display a point
        void output(){
            std::cout << "X: " << x << "\tY: " << y << std::endl;
        }
        // Operator overload for distance
        int operator-(point& other){
            return sqrt(pow(x-other.x, 2) + pow(y-other.y, 2));
        }
        // friend function for calculation of distance
        friend int distance(point A, point B);
};
int distance(point A, point B){
    return A-B;
}
int main(){
    int a,b;

    point p1;
    std::cout << "Enter point 1:\n";    std::cin>>a;   std::cin>>b;    
    p1.input(a,b);
    p1.output();

    point p2;
    std::cout << "Enter point 2:\n";    std::cin>>a;   std::cin>>b;    
    p2.input(a,b);
    p2.output();
    
    std::cout << "Distance:\t" << distance(p1,p2)<< std::endl;
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
