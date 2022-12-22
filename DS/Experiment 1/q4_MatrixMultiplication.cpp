/*
4. Write a program showing the implementation of Matrix Multiplication.
*/
#include <iostream>
#include <vector>

using namespace std;

// Function to perform matrix multiplication
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B){
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
void print(vector<vector<int>>&A){
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
// Driver function
int main()
{
    // Initialize two matrices
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    cout << "Matrix A : " << endl;
    print(A);
    cout << "Matrix B : " << endl;
    print(B);
    // Perform matrix multiplication
    vector<vector<int>> C = multiply(A, B);

    // Print the result
    cout << "Result of matrix multiplication:" << endl;
    print(C);

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
