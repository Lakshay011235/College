/*
1. Write a program showing the implementation of Insertion sort?
*/
#include <iostream>
#include <vector>

// Function to sort an array using insertion sort
void insertionSort(std::vector<int>& arr)
{
    int n = arr.size();

    // Iterate over the array, starting from the second element
    for (int i = 1; i < n; i++) {
        // Get the current element
        int curr = arr[i];

        // Compare the current element with the elements to its left, until it is in the correct position
        int j = i - 1;
        
        while (j >= 0 && arr[j] > curr) {
            // Shift the elements to the right to make room for the current element
            arr[j + 1] = arr[j];
            j--;
            }

        // Insert the current element into its correct position
        arr[j + 1] = curr;
    }
}

int main()
{
    // Test the insertion sort function
    std::vector<int> arr = { 4, 2, 1, 3, 6, 5 };
    insertionSort(arr);

    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
