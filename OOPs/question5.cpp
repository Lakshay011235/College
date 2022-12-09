/*
Implement a class string containing the following functions:
a. Overload + operator to carry out the concatenation of strings.
b. Overload = operator to carry out string copy.
c. Overload <= operator to carry out the comparison of strings.
d. Function to display the length of a string.
e. Function tolower( ) to convert upper case letters to lower case.
f. Function toupper( ) to convert lower case letters to upper case.
*/
#include <iostream>
#include <algorithm>
#include <string>

class String {
    public:
        // Data member to store the string
        std::string str_;
        
        // Parametrized Constructor
        // str_ is the actual default string type
        String(std::string str) : str_(str) {}

        // Overload + operator to concatenate two strings
        String operator+(String& other){
            return String(str_ + other.str_);
        }

        // Overload = operator to copy a string
        String& operator=(String& other){
            str_ = other.str_;
            return *this;
        }

        // Overload <= operator to compare two strings
        bool operator<=(String& other){
            return str_ <= other.str_;
        }

        // Method to get the length of the string
        int length() const {
            return str_.length();
        }

        // Method to convert the string to lower case (Using Algorithm header) 
        void tolower() {
            std::transform(str_.begin(), str_.end(), str_.begin(), ::tolower);
        }

        // Method to convert the string to upper case (Using Algorithm header) 
        void toupper() {
            std::transform(str_.begin(), str_.end(), str_.begin(), ::toupper);
        }
        // Overloaded << operator to output the string
        friend std::ostream& operator<<(std::ostream& os, String& Str) {
            return os << Str.str_;
        }
};

int main() {
    // Create two string objects
    String str1("Hello ");
    String str2("World");
    std::cout << "str1 = " << str1 << '\n';
    std::cout << "str2 = " << str2 << '\n';

    // Use the + operator to concatenate the strings
    String str3 = str1 + str2;
    std::cout << "str3 (str1+str2) = " << str3 << '\n';

    // Use the = operator to copy the value of one string to another
    str1 = str3;
    std::cout << "str1 (=str3) = " << str1 << '\n';

    // Use the <= operator to compare two strings
    bool is_smaller = (str1 <= str2);
    std::cout << "str1 is " << (is_smaller ? "smaller" : "larger") << "than str2\n";

    // Use the length function to get number of characters in string
    std::cout << "length of str1 = " << str1.length() << '\n';

    // Use of to_lower() function in string
    str1.tolower();
    std::cout << "to_lower(str1) = " << str1 << '\n';

    // Use of to_upper() function in string
    str1.toupper();
    std::cout << "to_upper(str1) = " << str1 << '\n';

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}