/*
6. Write a program showing the implementation of Heap sort (can be either min or max heap)?
*/
#include <iostream>
#include <vector>

// Function to heapify a subtree rooted at index i
// The subtree is assumed to already satisfy the max heap property, except for possibly the root node
void heapify(std::vector<int>& arr, int n, int i)
{
    // Set up variables to store the root node and its children
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger than the root, set the largest value to the left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest value so far, set the largest value to the right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the root node is not the largest value, swap it with the largest value and heapify the affected subtree
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Function to sort an array using heap sort
void heapSort(std::vector<int>& arr)
{
    int n = arr.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one, placing them at the end of the array
    for (int i = n - 1; i >= 0; i--) {
        // Swap the root node (maximum value) with the last element in the heap
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the remaining elements
        heapify(arr, i, 0);
    }
}

int main()
{
    // Test the heap sort function
    std::vector<int> arr = { 4, 2, 1, 3, 6, 5 };
    heapSort(arr);

    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
