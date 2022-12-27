/*
Write  a  program  to  illustrate  how  to  define  and  declare  a  class  template  for  reading  two  data  items from the keyboard and to find their sum.
*/
#include <iostream>

using namespace std;

// Class template for calculating the sum of two data items
template <typename T>
class Sum {
private:
    T a, b;

public:
    Sum() {
        cout << "Enter two values: ";
        cin >> a >> b;
    }

    T getSum() {
        return a + b;
    }
};

int main() {
    // Declare a Sum object for integers
    Sum<int> intSum;
    cout << "Sum of integers: " << intSum.getSum() << endl;

    // Declare a Sum object for floats
    Sum<float> floatSum;
    cout << "Sum of floats: " << floatSum.getSum() << endl;

    // Declare a Sum object for characters
    Sum<char> charSum;
    cout << "Sum of characters: " << charSum.getSum() << endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
