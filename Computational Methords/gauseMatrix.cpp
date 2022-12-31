#include <iostream>
#include <iomanip>
#include <string>
// Prints matrix in a matrix format
void print_matrix(float matrix[3][4]){
    std::cout << std::setprecision(4)
    << matrix[0][0] <<"\t" << matrix[0][1] <<"\t" << matrix[0][2] <<"\t" << matrix[0][3] << std::endl
    << matrix[1][0] <<"\t" << matrix[1][1] <<"\t" << matrix[1][2] <<"\t" << matrix[1][3] << std::endl
    << matrix[2][0] <<"\t" << matrix[2][1] <<"\t" << matrix[2][2] <<"\t" << matrix[2][3] << std::endl
    << std::endl;
}
void fill_matrix(float matrix[3][4]){
    for (int i = 0; i < 3; i++){
        std::cout << "Row " << i << " : ";
        std::cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2] >> matrix[i][3];
    }
}
void gaussElimination(float matrix[3][4]){
    /*
    for all j < i => lower triangular
    r1 -> r1 - (r10/r00)*r0     ==>  i = 1, j = 0
    r2 -> r2 - (r20/r00)*r0     ==>  i = 2, j = 0

    r2 -> r2 - (r21/r11)*r1     ==>  i = 2, j = 1

    r(i) -> r(i) - [r(i)(j) / r(j)(j)] * r(j) for all i=j+1 to rows and  j = 0 to col-2
        .
        .
    */
    for (int j = 0; j < 2; j++) {
        for (int i = j+1; i < 3; i++) {
            float decrement = matrix[i][j]/matrix[j][j];        //[r(i)(j) / r(j)(j)]

            // for all elements in row
            for (int k = 0; k < 4; k++) {
                matrix[i][k] = matrix[i][k] - decrement*matrix[j][k];
            }
        }
    }    
}
void gaussJordanElimination(float matrix[3][4]) {
    /*
        column 0                         === j = 0
    r0 -> r0 - (1   / r00)*r0  == 1   
    r1 -> r1 - (r10 / r00)*r0  == 0
    r2 -> r2 - (r20 / r00)*r0  == 0
        
        column 1                         === j = 1
    r1 -> r1 - (1   / r11)*r1  == 1
    r0 -> r0 - (r01 / r11)*r1  == 0
    r2 -> r2 - (r21 / r11)*r1  == 0

        column 2                         === j = 2
    r2 -> r2 - (1   / r22)*r2  == 1
    r0 -> r0 - (r02 / r22)*r2  == 0
    r1 -> r1 - (r12 / r22)*r2  == 0
        .
        .
    */
    for (int j = 0; j < 3; j++) {
        // for all elements in row
        float decrement = (1/matrix[j][j]);
        for (int k = 0; k < 4; k++) {
            matrix[j][k] = decrement*matrix[j][k];
        }
        for (int i = 0; i < 3; i++) {
            if (i!=j) {
                decrement = matrix[i][j]/matrix[j][j];
                for (int k = 0; k < 4; k++) {
                    matrix[i][k] = matrix[i][k] - decrement*matrix[j][k];
                }
            }
        }
    }
}

int main()
{
    float a[3][4] = {2,3,-1,5,3,2,1,10,1,-5,3,0};
    float b[3][4] = {1,1,1,-3,2,-1,-1,-3,1,-1,1,-9};

    //fill_matrix(a);
    print_matrix(b);
    gaussJordanElimination(b);
    print_matrix(b);

    return 0;
}