/*
2. Write a program showing the implementation of Linear search.
*/
#include <iostream>

template <typename T>
int linearSearch(T element, T array[], int arr_size){
    int index;
    //Performing Linear Search
    for(index = 0; index < arr_size ; index++) {
        if (array[index] == element) {
            return index;   //return at first instance
        }
    }
    //If value is not in array
    return -1;
}

int main()
{
    int arr[10] = {8,9,5,4,7,3,1,5,6,12};
    int size_arr = (sizeof(arr)/sizeof(int));

    //Showing user the array to perform search operation
    std::cout << "Array:\t";
    for(int i = 0;i<10;i++) std::cout << arr[i] << " ";

    //Asking for element to find in array
    int ele;
    std::cout << "\nElement to find: ";  std::cin >> ele;

    //Linear Search Operation
    int foundAt = linearSearch(ele, arr, size_arr);

    //Returning result after searching
    if (foundAt > 0) std::cout << "Value <" << ele <<"> found at index: " << foundAt << std::endl;
    else std::cout << "Value <" << ele << "> is not in the array" << std::endl;
    
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}