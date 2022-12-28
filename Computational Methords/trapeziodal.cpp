#include <iostream>
using namespace std;

float calc(float x){
    return x+1;
}

int main(){
    float lower, upper;
    std::cout << "Enter lower limit : "; cin >> lower;
    std::cout << "Enter upper limit : "; cin >> upper;

    int n;
    std::cout << "Enter the number of intervals : " ; cin >> n;

    float h = (upper-lower)/n;
    float ans = calc(lower);
    ans += calc(upper);
    for (float i = lower + h; i < upper; i = i + h){
        ans += 2*calc(i);
    }
    ans = (h*ans)/2;
    std::cout << "Answer : " << ans << std::endl;
    cout << "\nWritten by: Lakshay Sharma 02396402721" << endl;
    return 0;
}