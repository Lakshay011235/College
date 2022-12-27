/*
Create a class TIME with members hours, minutes and seconds. Take input, add two-time objects and passing objects to function and display the result.
*/
#include <iostream>

using namespace std;

// Time class with member variables hours, minutes, and seconds
class Time {
public:
    int hours;
    int minutes;
    int seconds;
};

// Function to add two Time objects and return the result as a Time object
Time add(Time t1, Time t2) {
    Time t3;
    t3.seconds = t1.seconds + t2.seconds;
    t3.minutes = t1.minutes + t2.minutes + t3.seconds / 60;
    t3.hours = t1.hours + t2.hours + t3.minutes / 60;
    t3.minutes %= 60;
    t3.seconds %= 60;
    return t3;
}

int main() {
    // Take input for two Time objects
    Time t1, t2;
    cout << "Enter time 1 (hours minutes seconds): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;
    cout << "Enter time 2 (hours minutes seconds): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    // Add the two Time objects and store the result in a third Time object
    Time t3 = add(t1, t2);

    // Display the result
    cout << "Time 1: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds << endl;
    cout << "Time 2: " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << endl;
    cout << "Time 3: " << t3.hours << ":" << t3.minutes << ":" << t3.seconds << endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
