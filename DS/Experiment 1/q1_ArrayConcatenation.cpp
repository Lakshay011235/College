/*
1. Write a program showing the implementation of array concatenation.
*/
#include <iostream>

int main() {
    int arr1[] = {2,5,6,8,9,23};
    int arr2[] = {102,105,106,108,109};
    int size_arr1 = (sizeof(arr1) / sizeof(int));
    int size_arr2 = (sizeof(arr2) / sizeof(int));
    int size_arr3 = (size_arr1+size_arr2);

    //Memory gets allocated for new array
    int arr3[size_arr3]; 

    //loop over first array and add its elements to final array
    for (int i = 0; i < size_arr1; i++)    arr3[i] = arr1[i];
    
    //loop over first array and add its elements to final array
    for (int i = 0; i < size_arr2; i++)    arr3[i+size_arr1] = arr2[i];
    
    //Print resulting arrays
    std::cout << "Array 1 :\t";
    for (int i = 0; i < size_arr1; i++) std::cout << arr1[i] << " ";
    std::cout << std::endl;

    std::cout << "Array 2 :\t";
    for (int i = 0; i < size_arr2; i++) std::cout << arr2[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Array 3 :\t";
    for (int i = 0; i < size_arr3; i++) std::cout << arr3[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nWritten By: Lakshay Sharma 02396402721" << std::endl;
    return 0;
}