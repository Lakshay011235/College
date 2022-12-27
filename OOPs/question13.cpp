/*
Create class first with data members book no, book name and member function getdata and  putdata. Create  a  class  second  with  data  members  author  name,  publisher  and  members  getdata  and  showdata. Derive a class third from first and second with data member no of pages and year of publication. Display all this information using array of objects of third class. (Multiple Inheritance)
*/
#include <iostream>
#include <string>

using namespace std;

// First class with data members book_no and book_name
// and member functions getdata and putdata
class First{
public:
    int book_no;
    string book_name;
    void getdata(){
        cout << "Enter book number: ";
        cin >> book_no;
        cout << "Enter book name: ";
        cin >> book_name;
    }
    void putdata(){
        cout << "Book number: " << book_no << endl;
        cout << "Book name: " << book_name << endl;
    }
};

// Second class with data members author_name and publisher
// and member functions getdata and putdata
class Second{
public:
    string author_name;
    string publisher;
    void getdata(){
        cout << "Enter author name: ";
        cin >> author_name;
        cout << "Enter publisher: ";
        cin >> publisher;
    }
    void showdata(){
        cout << "Author Name: " << author_name << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

// Derived Class Third from class First and Second
// and data members no_of_pages and year_of_publication
class Third : public First, public Second{
public:
    int no_of_pages;
    int year_of_publication;
    void getdata(){
        First::getdata();
        Second::getdata();
        cout << "Enter number of pages: ";
        cin >> no_of_pages;
        cout << "Enter year of publication: ";
        cin >> year_of_publication;
    }
    void putdata(){
        First::putdata();
        Second::showdata();
        cout << "Number of Pages: " << no_of_pages << endl;
        cout << "Year of publication: " << year_of_publication << endl;
    }
};

int main(){
    Third book[3];  // array of objects of Third class

    // Input data for each object
    for (int i = 0; i < 3; i++){
        cout << "Enter data for book " << i + 1 << ":" << endl;
        book[i].getdata();
    }
    cout << endl;

    // Display data for each object
    for (int i = 0; i < 3; i++){
        cout << "Data for book " << i + 1 << ":" << endl;
        book[i].putdata();
        cout << endl;
    }
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
