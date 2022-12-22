#include <bits/stdc++.h>
using namespace std;

// Function to find the product term
float proterm(int i, float value, float x[]){
	float pro = 1;
	for (int j = 0; j < i; j++) {
		pro = pro * (value - x[j]);
	}
	return pro;
}

// Function for calculating divided difference table
void dividedDiffTable(float x[], float y[][10], int n){
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
		}
	}
}

// Function for applying Newton's divided difference formula
float applyFormula(float value, float x[], float y[][10], int n){
	float sum = y[0][0];
	for (int i = 1; i < n; i++) {
	    sum = sum + (proterm(i, value, x) * y[0][i]);
	}
	return sum;
}
int main()
{
	// number of inputs given
	int n = 5;
	float value, sum, y[10][10];
	float x[] = { 2, 3, 5, 8, 12};

	// y[][] is used for divided difference
	// table where y[][0] is used for input
	y[0][0] = 10;
	y[1][0] = 15;
	y[2][0] = 25;
	y[3][0] = 40;
    y[4][0] = 60;

	// value to be interpolated
	value = 4;

    // Calculate the divided difference table
    dividedDiffTable(x, y, n);

	// printing the value
    cout << "X:\t2\t3\t5\t8\t12" << endl;
    cout << "F(x):\t10\t20\t25\t40\t60" << endl;
    cout << "value of X:" << value << endl;
    cout << "Ans:" << applyFormula(value, x, y, n);

    cout << "\nWritten by: Lakshay Sharma 02396402721" << endl;
	return 0;
}
