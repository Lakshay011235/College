/*
Write a program to perform addition of two complex numbers using constructor overloading. The
first constructor which takes no argument is used to create objects which are not initialized, second
which takes one argument is used to initialize real and imag parts to equal values and third which
takes two argument is used to initialized real and imag to two different values.
*/

#include <iostream>
using namespace std;
class Complex {
    public:
        int real;
        int imaginary;
        Complex(){                              //DefaultConstructor 
        real = 0;
        imaginary = 0;
        }
        Complex(int a){                         // Single Parametrized Constructor 
        real = a;
        imaginary = a;
        }
        Complex(int r, int i){                  // Double Parametrized Constructor
        real = r;
        imaginary = i;
        }

        Complex addComplexNumber(Complex C1, Complex C2){          // Member Function to perform addition
            Complex res;
            res.real = C1.real + C2.real;
            res.imaginary = C1.imaginary + C2.imaginary;
            return res;
        }
    };
int main(){
    Complex C1(3);
    cout << "Complex number 1 : " << C1.real<< " + i" << C1.imaginary << endl;
    Complex C2(11,13);
    cout << "Complex number 2 : " << C2.real << " + i" << C2.imaginary << endl;

    Complex C3;
    C3 = C3.addComplexNumber(C1, C2);
    cout << "Sum of complex number : "<< C3.real << " + i"<< C3.imaginary << endl;
    cout << "Written By :> Lakshay Sharma :: 02396402721";
return 0;
}
    