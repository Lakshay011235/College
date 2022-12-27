/*
Write  a  program  to  demonstrate  the  use  of  special  functions,  constructor  and  destructor  in  the  class template. The program is used to find the bigger of two entered numbers. 
*/
#include <iostream>

template <typename T>
class MaxFinder {
private:
    T a, b;

public:
    MaxFinder(T x, T y) : a(x), b(y) {
        std::cout << "Constructor called" << std::endl;
    }

    ~MaxFinder() {
        std::cout << "Destructor called" << std::endl;
    }

    T getMax() {
        return (a > b) ? a : b;
    }
};

int main() {
    MaxFinder<int> *finder = new MaxFinder<int>(3, 4);
    std::cout << "Max: " << finder->getMax() << std::endl;
    delete finder;
    
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
