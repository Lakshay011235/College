/*
Write a program to generate a Fibonacci series using Copy Constructor
*/
#include <iostream>
#include <vector>
class Fib{
    
    public:
        std::vector<int> fib_;

        //Default values => 1,1
        Fib(){          
            fib_.push_back(1);
            fib_.push_back(1);
        }               
        /*
            Copy constructor holding values found by previous object
            Generates required number values on call        
        */
        Fib(Fib& other, int steps=0){
            other.generateNext(steps);
            fib_= other.fib_;
        }
        void generateNext(int steps=1){
            for (int i = 0; i < steps; i++){
                fib_.push_back(*(fib_.end()-1) + *(fib_.end()-2));
            }
        }
        // Overloaded << operator to output the list
        friend std::ostream& operator<<(std::ostream& os, Fib& fib) {
            std::vector<int>& v = fib.fib_;
            for (int x : v) std::cout << x << " ";
            return os << "";
        }
};
int main() {
    Fib s1;
    int n;
    std::cout << "Enter the number of values to generate: ";
    std::cin >> n;
    s1.generateNext(n);
    std::cout << "Sequence: \t\t\t" << s1 << std::endl;

    Fib s2(s1);
    std::cout << "Copied Sequence: \t\t" << s2 << std::endl;

    std::cout << "\nEnter the number of values to generate extra in copied sequence: ";
    std::cin >> n;

    Fib s3(s2,n);
    std::cout << "Extended Copied Sequence: \t" << s2 << std::endl;
        
    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}