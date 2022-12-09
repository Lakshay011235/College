/*
Create a class Student, which have data members as name, branch, roll no., age, sex, five subjects. Display the name of student & his percentage who has more than 70%. Use array of objects. [Array of objects]
*/
#include <iostream>
#include <array>
#include <string>
class Student {
    public:
        // Data members
        std::string name_;
        std::string branch_;
        int roll_no_;
        int age_;
        char sex_;
        std::array<int, 5> marks_;
        // Constructor with initializer list to initialize data members
        Student(std::string name, std::string branch, int roll_no, int age, char sex, std::array<int, 5> marks){
            name_ = name;
            branch_ = branch;
            roll_no_ = roll_no;
            sex_ = sex;
            marks_ = marks;
        }
        // Method to calculate the percentage of marks obtained by the student
        double percentage(){
            int sum = 0;
            for (auto mark : marks_) {
                sum += mark;
            }
            return sum / 5.0;
        }   
};

int main() {
    // Create an array of objects of the Student class
    std::array<Student, 5> students {
        Student("John", "Computer Science", 1, 18, 'M', {85, 92, 75, 91, 78}),
        Student("Jane", "Electrical Engineering", 2, 19, 'F', {70, 65, 80, 75, 78}),
        Student("Bob", "Mechanical Engineering", 3, 20, 'M', {65, 72, 68, 62, 60}),
        Student("Alice", "Electronics Engineering", 4, 21, 'F', {95, 98, 12, 94, 10}),
        Student("David", "Civil Engineering", 5, 22, 'M', {80, 75, 70, 85, 80})
    };  
    // Loop through all the students and display the name of the student
    // who has obtained more than 70% marks
    for (auto& student : students) {
        if (student.percentage() > 70) {
            std::cout << student.name_ << " has obtained more than 70% marks.\n";
        }
    }
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
