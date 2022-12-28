/*
3. Write a program showing the implementation of Selection sort?
*/
#include <iostream>
#include <vector>

// Function to sort an array using selection sort
void selectionSort(std::vector<int>& arr)
{
    int n = arr.size();

    // Iterate over the array, starting from the first element
    for (int i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted portion of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            std::cout << "Step " << i << "." << j << " : \t" ;
            for (int x : arr) {
                std::cout << x << " ";
            }
            std::cout << "\t<" << arr[minIndex] << ">" << std::endl;
        }

        // Swap the minimum element with the first element of the unsorted portion
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        std::cout << "Step " << i << "->" << " : \t" ;
        for (int x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl << std::endl;
    }
}

int main()
{
    // Test the selection sort function
    std::vector<int> arr = { 4, 2, 1, 3, 6, 5 };
    std::cout << "Input : \t" ;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    selectionSort(arr);
    
    std::cout << "Output : \t" ;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
