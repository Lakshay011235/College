/*
Q.  Write a program to perform linear search on an array
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1,3,5,7,9,11,13,15,17,19};
    int elem; int check = 0;
    cout << "Array:\t";
    for(int i = 0;i<10;i++) {
        cout << arr[i] << "\t";
    }
    cout << "\nElement to find:";
    cin >> elem;
    for(int i = 0;i<10;i++) {
        if (arr[i] == elem) {
            cout << "value:" << elem << "\nIndex:" << i;
            check = 1;
        }
    }
    cout << ((check==0)?"There is no such value":"");
    cout << "Lakshay Sharma :: 02396402721";
    return 0;
}