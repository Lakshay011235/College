/*
Design  three  classes  STUDENT,  EXAM,  and  RESULT.  The  STUDENT  class  has  data  members such as  roll no, name.  Create  a class EXAM  by inheriting the  STUDENT class. The EXAM  class adds data members representing the marks scored in six subjects. Derive the RESULT from the EXAM class and has  its  own  data  members  such  as  total  marks.  WAP  to  model  this  relationship.(Multilevel Inheritance) 
*/
#include <iostream>
#include <string>

using namespace std;

// STUDENT class with data members roll no and name
class STUDENT {
public:
    int roll_no;
    string name;
    void getdata()
    {
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter name: ";
        cin >> name;
    }
    void putdata()
    {
        cout << "Roll number: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};

// EXAM class derived from STUDENT class
// with data members representing the marks scored in six subjects
class EXAM: public STUDENT {
public:
    int marks[6];
    void getdata()
    {
        STUDENT::getdata();
        cout << "Enter marks for six subjects: ";
        for (int i = 0; i < 6; i++)
            cin >> marks[i];
    }

    void putdata()
    {
        STUDENT::putdata();
        cout << "Marks: ";
        for (int i = 0; i < 6; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};

// RESULT class derived from EXAM class
// with its own data member total marks
class RESULT: public EXAM {
public:
    int total_marks;
    void getdata()
    {
        EXAM::getdata();
        total_marks = 0;
        for (int i = 0; i < 6; i++)
            total_marks += marks[i];
    }

    void putdata()
    {
        EXAM::putdata();
        cout << "Total marks: " << total_marks << endl;
    }
};

int main()
{
    RESULT student[2];  // array of objects of RESULT class

    // Input data for each object
    for (int i = 0; i < 2; i++) {
        cout << "Enter data for student " << i + 1 << ":" << endl;
        student[i].getdata();
    }

    cout << endl;

    // Display data for each object
    for (int i = 0; i < 2; i++) {
        cout << "Data for student " << i + 1 << ":" << endl;
        student[i].putdata();
        cout << endl;
    }

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
