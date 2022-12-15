/*
3. Write a program showing the implementation of Binary search.
*/
#include <iostream>

/*Iterative Approach*/
template <typename T>
int binarySearchI(T element, T array[], int lower_index, int upper_index){
    while (lower_index <= upper_index) {
        int middle_index = lower_index + (upper_index - lower_index) / 2;

        // Check if element is present at mid
        if (array[middle_index] == element) return middle_index;
 
        // If element smaller than middle, ignore right half
        if (element < array[middle_index]) upper_index = middle_index - 1;
 
        // If element is greater than middle, ignore left half
        else lower_index = middle_index + 1;
    }
    // Value is not found in array 
    return -1;
}

/*Recursive Approach*/
template <typename T>
int binarySearchR(T element, T array[], int lower_index, int upper_index){
    if (upper_index >= lower_index) {
        int middle_index = lower_index + (upper_index - lower_index) / 2;
 
        // If the element is present at the middle
        if (array[middle_index] == element) return middle_index;
 
        // If element is smaller than middle, then element is in left subArray
        if (element < array[middle_index])
            return binarySearchR(element, array, lower_index, middle_index - 1);
 
        // Else, element is in right subArray
        return binarySearchR(element, array, middle_index + 1, upper_index);
    }
    // Value is not found in array 
    return -1;
}

int main()
{
    int arr[10] = {1,2,3,5,7,11,13,17,19,23};
    int size_arr = (sizeof(arr)/sizeof(int));

    //Showing user the sorted array to perform search operation
    std::cout << "Array:\t";
    for(int i = 0;i<10;i++) std::cout << arr[i] << " ";

    //Asking for element to find in array
    int ele;
    std::cout << "\nElement to find: ";  std::cin >> ele;

    /*Iterative Binary Search Operation*/
    int foundAt = binarySearchI(ele, arr, 0, size_arr);
    //Returning result after searching
    std::cout << "Iterative Binary Search >> ";
    if (foundAt > 0) std::cout << "Value <" << ele << "> found at index: " << foundAt << std::endl;
    else std::cout << "Value <" << ele << "> is not in the array" << std::endl;
    
    /*Recursive Binary Search Operation*/
    foundAt = binarySearchR(ele, arr, 0, size_arr);
    //Returning result after searching
    std::cout << "Recursive Binary Search >> ";
    if (foundAt > 0) std::cout << "Value <" << ele << "> found at index: " << foundAt << std::endl;
    else std::cout << "Value <" << ele << "> is not in the array" << std::endl;
    
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}