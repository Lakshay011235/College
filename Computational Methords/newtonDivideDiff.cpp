#include <iostream>
#include <vector>

using namespace std;

// String Parsing
vector<double> split(string str) {
    string str1;
    vector<double> vect;
    string search;
    for (int i=0; i < str.length(); i++ ) {
        search = str[i];
        if (search != "\t") {
            str1 = str1 + str[i];
        }
        else {
            vect.push_back(stof(str1));
            str1 = "";
        }
    }
    vect.push_back(stof(str1));
    return vect;
}
// Function to calculate the divided difference coefficient
double dividedDifference(vector<double> &x, vector<double> &y, int i, int j)
{
    if (j == 0)
        return y[i];

    return (dividedDifference(x, y, i + 1, j - 1) - dividedDifference(x, y, i, j - 1)) / (x[i + j] - x[i]);
}

// Function to evaluate the polynomial at a given value of x
double newtonInterpolation(vector<double> &x, vector<double> &y, double xi)
{
    double result = y[0];
    double product;
    for (int i = 1; i < x.size(); i++)
    {
        product = 1;
        for (int j = 0; j < i; j++)
            product = product * (xi - x[j]);
        result += dividedDifference(x, y, 0, i) * product;
    }
    return result;
}

int main()
{
    string abc;
    vector<double> x, y;
    cout << "Use space to seperate\n";

    cout << "X:\t";
    getline(cin,abc);
    x = split(abc);

    cout << "F(x):\t";
    getline(cin,abc);
    y = split(abc);

    double xi;
    cout << "value of X:";
    cin >> xi;

    cout << "Ans: " << newtonInterpolation(x, y, xi) << endl;

    return 0;
}