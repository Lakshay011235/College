/*
Write a program to add two complex numbers
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
        Complex(int r, int i){                  // Parametrized Constructor
        real = r;
        imaginary = i;
        }

        Complex addComplexNumber(Complex C1, Complex C2){          // MemberFunction toperformaddition
            Complex res;
            res.real = C1.real + C2.real;
            res.imaginary = C1.imaginary + C2.imaginary;
            return res;
        }
    };
int main(){
    Complex C1(1,3);
    cout << "Complex number 1 : " << C1.real<< " + i" << C1.imaginary << endl;
    Complex C2(11,13);
    cout << "Complex number 2 : " << C2.real << " + i" << C2.imaginary << endl;

    Complex C3;
    C3 = C3.addComplexNumber(C1, C2);
    cout << "Sum of complex number : "<< C3.real << " + i"<< C3.imaginary << endl;
    cout << "Lakshay Sharma :: 02396402721";
return 0;
}
    