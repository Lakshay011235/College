/*
4. Write a program showing the implementation of Quick sort?
*/
#include <iostream>
#include <vector>

// Function to partition an array around a pivot
int partition(std::vector<int>& arr, int low, int high)
{
    // Choose the pivot as the last element in the array
    int pivot = arr[high];

    // Set up two indices, one for the left side of the pivot and one for the right side
    int i = low - 1;
    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot, swap it with the element at the left index
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot with the element at the left index + 1
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the index of the pivot
    return i + 1;
}

// Recursive function to sort an array using quick sort
void quickSort(std::vector<int>& arr, int low, int high)
{
    if (low < high) {
        // Partition the array around a pivot and get the pivot's index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the left and right halves of the array
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    // Test the quick sort function
    std::vector<int> arr = { 4, 2, 1, 3, 6, 5 };
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
