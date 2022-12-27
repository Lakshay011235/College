/*
Create a base class basic info with data members name, roll no, sex and two member functions getdata 
and display. Derive a class physical fit from basic_info which has data members height and weight and 
member functions getdata display. Display all the information using object of derived class.(Single 
Inheritance)
*/
#include <iostream>

// Base class
class BasicInfo {
public:
    std::string name;
    int roll_no;
    char sex;
    void getdata(){
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter roll number: ";
        std::cin >> roll_no;
        std::cout << "Enter sex (M/F): ";
        std::cin >> sex;
    }
    void display(){
        std::cout << "Name: \t\t" << name << std::endl;
        std::cout << "Roll number: \t" << roll_no << std::endl;
        std::cout << "Sex: \t\t" << sex << std::endl;
    }
};

// Derived class
class PhysicalFit : public BasicInfo {
public:
    float height;
    float weight;
    void getdata(){
        // Call the getdata() function of the base class to get the basic info
        BasicInfo::getdata();
        std::cout << "Enter height (in meters): ";
        std::cin >> height;
        std::cout << "Enter weight (in kg): ";
        std::cin >> weight;
    }
    void display(){
        // Call the display() function of the base class to display the basic info
        BasicInfo::display();
        std::cout << "Height: \t" << height << "m" << std::endl;
        std::cout << "Weight: \t" << weight << "kg" << std::endl;
    }
};

int main() {
    // Create an object of the derived class
    PhysicalFit student;

    // Get the data for the object
    student.getdata();

    // Display the data for the object
    student.display();

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
