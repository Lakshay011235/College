/*
5. Write a program showing the implementation of Bubble sort?
*/
#include <iostream>
#include <vector>

// Function to sort an array using bubble sort
void bubbleSort(std::vector<int>& arr)
{
    int n = arr.size();

    // Iterate over the array, starting from the second element
    for (int i = 0; i < n - 1; i++) {
        // Flag to track if any swaps were made in the current pass
        bool swapped = false;

        // Iterate over the unsorted portion of the array
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps were made, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main()
{
    // Test the bubble sort function
    std::vector<int> arr = { 4, 2, 1, 3, 6, 5 };
    bubbleSort(arr);

    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
