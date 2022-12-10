/*
Write a program to overload unary operator ++.
*/
#include <iostream>

class Integer {
public:
  // Constructor to initialize the integer value
  Integer(int value) : value_(value) {}

  // Overload ++ when used as prefix
  Integer operator ++ () {
    ++value_;
    return *this;
  }
  // Overload ++ when used as postfix
  Integer operator ++ (int) {
    value_++;
    return *this;
  }

  // Overloaded << operator to output the integer value
  friend std::ostream& operator<<(std::ostream& os,const Integer& obj) {
    return os << obj.value_;
  }

private:
  // The integer value
  int value_;
};

int main() {
  // Create an Integer object
  Integer n(10);
  std::cout << "n = " << n << '\n';  // ++n = 10

  // Use the ++ operator to increment the integer value
  std::cout << "++n = " << (++n) << '\n';  // ++n = 11
  std::cout << "n++ = " << (n++) << '\n';  // n++ = 11

  std::cout << "Written By :> Lakshay Sharma :: 02396402721";
  return 0;
}
