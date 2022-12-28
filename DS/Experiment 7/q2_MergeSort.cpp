/*
2. Write a program showing the implementation of Merge sort?
*/
#include <iostream>
#include <vector>

// Function to merge two sorted arrays
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right)
{
    // Create a result vector
    std::vector<int> result;

    // Set up two indices, one for each array
    int i = 0, j = 0;

    // Iterate until one of the indices reaches the end of its array
    while (i < left.size() && j < right.size()) {
        // Compare the elements at the current indices and add the smaller one to the result
        if (left[i] < right[j]) {
            result.push_back(left[i++]);
        }
        else {
            result.push_back(right[j++]);
        }
    }

    // Add the remaining elements from the left array, if any
    while (i < left.size()) {
        result.push_back(left[i++]);
    }

    // Add the remaining elements from the right array, if any
    while (j < right.size()) {
        result.push_back(right[j++]);
    }
    std::cout << "Merged : \t" ;
    for (int x : result) {
        std::cout << x << " ";
    }
    std::cout << "\n" ;
    return result;
}

// Recursive function to sort an array using merge sort
std::vector<int> mergeSort(std::vector<int>& arr)
{
    // Base case: If the array has 1 or fewer elements, it is already sorted
    if (arr.size() <= 1) {
        return arr;
    }

    // Split the array in half
    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    std::cout << "Left : \t" ;
    for (int x : left) {
        std::cout << x << " ";
    }
    std::cout << "\t\t" ;
    std::cout << "Right : \t" ;
    for (int x : right) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // Recursively sort the left and right halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    // Merge the sorted left and right halves
    return merge(left, right);
}

int main()
{
    // Test the merge sort function
    std::vector<int> arr = { 4, 2, 1, 3, 6, 5 };
    std::cout << "Input : \t" ;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    arr = mergeSort(arr);
    
    std::cout << "Output : \t" ;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}

