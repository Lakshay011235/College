#include <iostream>
using namespace std;

float f(float x) {  return x*x*x + x - 1;}

int main() {
     float a, b, x; int iter=100;
     cout << "Equation: x*x*x + x - 1" << endl;
     cout << "Lower limit:\t"; cin >> a;
     cout << "Upper limit:\t"; cin >> b;
     //if root is at the given limit
     cout << ((f(a)==0)?"root is:"+ to_string(a) :"");
     cout << ((f(b)==0)?"root is:"+ to_string(b) :"");
     //if there is no root in interval
     if (f(a)*f(b) >= 0) {
         cout << "There is no possible root in interval";
         exit(0);
     }
     cout << "Iteration\ta\t\tb\t\tx\t\tf(x)\n";
     for (int i=0;i<iter;i++) {
           x = b - f(b)*((b - a)/(f(b)-f(a)));
           cout << to_string(i+1) +"\t\t"+to_string(a)+"\t"+to_string(b)+"\t"+to_string(x)+"\t"+to_string(f(x))+"\n";
           if (abs(f(x)) < 0.000001) break;
           (f(x)<0) ? a=x : b=x;
     }
     cout << "\nThe nearest root is:" << x;
     cout << "\nWritten by: Lakshay Sharma 02396402721" << endl;
}