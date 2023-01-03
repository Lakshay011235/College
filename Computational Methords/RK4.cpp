#include <iostream>

double f(double x, double y){
    return (x+y*y);
}

int main()
{
    double x0, y0, h, xn, yn;
    double k1, k2, k3, k4, k;
    int n;

    std::cout << "Equation : x+y^2" << std::endl;
    std::cout << "Initial Condition:\tx0 y0 :\t\t"; std::cin >> x0 >> y0;
    std::cout << "Value required at:\txn :\t\t"; std::cin >> xn;
    std::cout << "Number of steps:\tn :\t\t"; std::cin >> n;

    h = (xn - x0)/n;

    std::cout << std::endl << "x\ty" << std::endl;

    for (int i = 0; i <= n; i++)
    {
        yn = y0;
        std::cout << x0 <<"\t"<< y0 << std::endl;   
        k1 = h * f(x0      , y0       );
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h  , y0 + k3  );
        k = ( k1 + 2*k2 + 2*k3 + k4 ) / 6;
        y0 += k;
        x0 += h;
    }
    
    std::cout << "\nValue of f at x=" << xn << " is :: " << yn << std::endl;
    std::cout << "\nWritten by: Lakshay Sharma 02396402721" << std::endl;
    return 0;
}
