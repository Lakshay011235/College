#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    //for reference and checking :: float a[3][4] = {2,3,-1,5,3,2,1,10,1,-5,3,0};  answer={1,2,3};
    int n;
    std::cout << "Enter number of Variables:\t"; std::cin >> n;

    float matrix[n][2*n];

    for (int i = 0; i < n; i++){
        std::cout << "Row " << i << " : ";
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
            if (i == j) matrix[i][j+n] = 1;
            else matrix[i][j+n] = 0;
        }
    }

    std::cout << "Original Matrix :" << std::endl;
    std::cout << std::setprecision(4);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cout << matrix[i][j] << "\t\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int j = 0; j < n; j++) {
        // for all elements in row
        float decrement = (1/matrix[j][j]);
        for (int k = 0; k < 2*n; k++) {
            matrix[j][k] = decrement*matrix[j][k];
        }
        for (int i = 0; i < n; i++) {
            if (i!=j) {
                decrement = matrix[i][j]/matrix[j][j];
                for (int k = 0; k < 2*n; k++) {
                    matrix[i][k] = matrix[i][k] - decrement*matrix[j][k];
                }
            }
        }
    }
    std::cout << "After Gauss Jordan Elimination " << std::endl <<std::endl;
    std::cout << "Inverse Matrix" << std::endl;

    std::cout << std::setprecision(2);
    for (int i = 0; i < n; i++){
        for (int j = n; j < 2*n; j++){
            std::cout << matrix[i][j] << "\t\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nWritten by: Lakshay Sharma 02396402721" << std::endl;
    return 0;
}