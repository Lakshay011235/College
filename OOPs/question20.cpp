/*
Write  a  program  to  define  the  function  template  for  calculating  the  square  of  given  numbers  with different data types
*/
#include <iostream>

using namespace std;

template <typename T>
T square(T x) {
    return x * x; 
}

int main() {
    int a = 3;
    cout << "Square of " << a << ": " << square(a) << endl;

    float b = 4.5;
    cout << "Square of " << b << ": " << square(b) << endl;

    char c = 'a';
    cout << "Square of " << c << ": " << square(c) << endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
