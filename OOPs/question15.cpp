/*
Create a base class called SHAPE. Use this class to store two double type values. Derive two specific classes  called  TRIANGLE  and  RECTANGLE  from  the  base  class.  Add  to  the  base  class,  a  member function  getdata  to  initialize  base class  data  members and  another  member  function  display  to  compute and display the area of figures. Make display a virtual function and redefine this function in the derived classes to suit their requirements. Using these three classes design a program that will accept driven of a TRIANGLE or RECTANGLE interactively and display the area.
*/
#include <iostream>

using namespace std;

// Base class SHAPE with data members to store two double values
class SHAPE {
protected:
    double x, y;

public:
    void getdata()
    {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    virtual void display()
    {
        // This function will be redefined in the derived classes
    }
};

// Derived class TRIANGLE from SHAPE
class TRIANGLE: public SHAPE {
public:
    void display()
    {
        cout << "Area of triangle: " << 0.5 * x * y << endl;
    }
};

// Derived class RECTANGLE from SHAPE
class RECTANGLE: public SHAPE {
public:
    void display()
    {
        cout << "Area of rectangle: " << x * y << endl;
    }
};

int main() {
    SHAPE *shape;  // pointer to base class
    char ch;

    cout << "Enter t for triangle or r for rectangle: ";
    cin >> ch;

    if (ch == 't')
        shape = new TRIANGLE;  // dynamic allocation of triangle object
    else
        shape = new RECTANGLE;  // dynamic allocation of rectangle object

    shape->getdata();
    shape->display();

    delete shape;  // deallocate memory

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
