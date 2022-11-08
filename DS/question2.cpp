/*
Q. Write a program to perform binary sort on an array
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1,3,5,7,9,11,13,15,17,19};
    int elem; int check = 0; int half; int len; int new_half;
    cout << "Array:\t";
    for(int i = 0;i<10;i++)             cout << arr[i] << "\t";
    cout << "\nElement to find:";       cin >> elem;
    len = sizeof(arr)/sizeof(arr[0]);
    half = ((len%2==0)  ? len/2 : (len+1)/2);
    if (arr[0] == elem) {
        cout << "\nElement:" << elem << "\nIndex:" << 0;
        check = 1;
        exit(0);
    }
    //Binary sort using while loop
    while (half > 0) {
        if (arr[half] == elem) {
            cout << "\nElement:" << elem << "\nIndex:" << half;
            check = 1;
            exit(0);
        }
        new_half = ((half%2==0)?half:half+1);
        half = ((arr[half] - elem > 0)? new_half/2 : (3*new_half)/2);
    }
    cout << ((check==0)?"There is no such value":"");
    cout << "Lakshay Sharma :: 02396402721";
    return 0;
}
