#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {return x*x*x + x - 1;}
double df(double x){return 3*x*x + 1;}

int main()
{   
    double x; int iter=100;
    cout << "Equation: x*x*x + x - 1" << endl;
    cout << "Assumed root:";
    cin >> x;
    cout << "Iteration\tx\t\tf(x)\n";
    for(int i = 0;i<iter;i++){
        x = x - (f(x)/df(x));
        cout << to_string(i+1)+"\t\t"+to_string(x)+"\t"+to_string(f(x))+"\n";
        if (abs(f(x)) < 0.00000001) break;
    }
    
    cout << "\nThe nearest root is:" << x << "\n";
    cout << "\nWritten by: Lakshay Sharma 02396402721" << endl;
    return 0;
}